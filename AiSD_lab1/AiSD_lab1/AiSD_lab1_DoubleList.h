#pragma once

#include <iostream>
#include <stdexcept> 

using namespace std;

class DoubleList {

private:

    class Node {
    public:
        size_t index; // index of element
        int value; // value of element
        Node* next; // pointer to the next element
        Node* prev; // pointer to the previous element
    };

    Node* head; // pointer to the begin of DoubleList
    Node* tail; // pointer to the end of DoubleList

public:

    // Constructor with value
    DoubleList(int value) {

        Node* buffer = new Node; // Create temporary node
        buffer->value = value;
        buffer->index = 0;
        buffer->next = tail;
        head = buffer;
        buffer->prev = NULL;
        tail = buffer;
    }

    // Constructor without value
    DoubleList() {
        head = tail = NULL;
        Node* buffer = new Node; // Create temporary node
        buffer->prev = NULL;
        buffer->next = NULL;
        buffer->value = NULL;
        buffer->index = 0;
    }

    // Destructor
    ~DoubleList() {
        clear();
    }

    // Add element before others
    void push_front(int value) {
        Node* buffer = new Node; // Create temporary node
        if (isEmpty() == 1) { // If DoubleList is empty
            buffer->value = value;
            buffer->index = 0;
            buffer->next = tail;
            head = buffer;
            buffer->prev = NULL;
            tail = buffer;
        }
        else {  // If DoubleList isn't empty
            buffer->value = value;
            buffer->index = 0;
            buffer->next = head;
            head->prev = buffer;
            head = buffer;
            head->prev = NULL;

            buffer = head;
            buffer = buffer->next;
            while (buffer != NULL)
            {
                buffer->index += 1;
                buffer = buffer->next;
            }
        }
    }

    // Add element after others
    void push_back(int value) {
        Node* buffer = new Node; // Create temporary node

        if (isEmpty() == 1) { // If DoubleList is empty
            buffer->value = value;
            buffer->index = 0;
            buffer->next = tail;
            head = buffer;
            buffer->prev = NULL;
            tail = buffer;
        }
        else { // If DoubleList isn't empty
            buffer->value = value;
            buffer->next = tail->next;
            buffer->prev = tail;
            buffer->index = buffer->prev->index + 1;
            tail->next = buffer;
            tail = buffer;
        }
    }

    // Delete first element
    void pop_front() {

        if (isEmpty() == 0) // If DoubleList isn't empty
        {
            Node* buffer = head; // Create temporary node
            head = head->next;
            head->prev = NULL;
            delete buffer;

            buffer = head;
            while (buffer != NULL)
            {
                buffer->index -= 1;
                buffer = buffer->next;
            }
        }
        else {
            throw invalid_argument("Double list is empty. First element cannot be deleted");
        }
    }

    // Delete last element
    void pop_back() {
        if (isEmpty() == 0) // If DoubleList isn't empty
        {
            Node* buffer = tail; // Create temporary node
            tail = tail->prev;
            tail->next = NULL;
            delete buffer;
        }
        else {
            throw invalid_argument("Double list is empty. Last element cannot be deleted");
        }
    }

    // Insert new element at user's position
    void insert(int value, size_t index) {
        if (index < get_size())
        {
            if (index == 0) { // If DoubleList isn't empty
                return push_front(value);
            }
            else // If DoubleList is empty
            {
                Node* buffer = head; // Create temporary node
                Node* insert = new Node;
                insert->value = value;
                insert->index = index;
                buffer = head;
                while (buffer->next->index < insert->index) {
                    buffer = buffer->next;
                }

                insert->next = buffer->next;
                insert->prev = buffer;
                buffer->next = insert;
                buffer = insert;
                buffer = buffer->next;

                while (buffer != NULL)
                {
                    buffer->index += 1;
                    buffer = buffer->next;
                }
            }
        }
        else {
            throw out_of_range("Position of element is larger than maximum Double list index");
        }
    }

    // Print element at user's position
    int at(size_t index) {
        if (index < get_size()) // If index is in DoubleList range
        {
            Node* buffer = head; // Create temporary node
            while (buffer != NULL) {
                if (buffer->index == index) {
                    /*cout << buffer->value;*/
                    return buffer->value;
                }
                buffer = buffer->next;
            }
        }
        else {
            throw out_of_range("Position of element is out of range Double list index");
        }
    }

    // Delete element at user's position
    void remove(size_t index) {
        if (index < get_size()) { // If index is in DoubleList range

            if (index == 0)
            {
                return pop_front();
            }
            else if (index == get_size() - 1)
            {
                return pop_back();
            }
            else {
                Node* buffer = head; // Create temporary node
                while (buffer->next != NULL) {
                    if (buffer->next->index == index) {
                        Node* remove = buffer->next;
                        buffer->next = remove->next;
                        remove->next->prev = buffer;
                        delete remove;
                    }
                    buffer = buffer->next;
                    buffer->index -= 1;
                    while (buffer->next != NULL)
                    {
                        buffer = buffer->next;
                        buffer->index -= 1;
                    }
                }
            }
        }
        else {
            throw out_of_range("Position of element is out of range Double list index");
        }
    }

    // Return size of Double list
    size_t get_size() {
        size_t listSize;
        if (tail == NULL) { listSize = 0; } // If DoubleList is empty
        else {
            Node* buffer = tail; // Create temporary node
            listSize = buffer->index;
            listSize += 1;
        }
        return listSize;
    }

    // Delete the Double list
    void clear() {
        Node* buffer = head; // Create temporary node
        while (head != NULL) {
            Node* buffer = head->next;
            delete head;
            head = buffer;
        }
        tail = head;
    }

    // Switch value of element at user's position
    void set(size_t index, int value) {
        if (index < get_size()) { // If index is in DoubleList range
            Node* buffer = head; // Create temporary node
            while (buffer != NULL) {
                if (buffer->index == index) {
                    buffer->value = value;
                }
                buffer = buffer->next;
            }
        }
        else {
            throw out_of_range("Position of element is out of range Double list index");
        }
    }

    // Check the empty of Double list
    bool isEmpty() {
        bool result = false;
        if (get_size() == NULL) result = true;
        return result;
    }

    // Reverse the Double list
    void reverse() {
        int number_left, number_right;
        Node* left = head, * right = head;
        while (right->next != NULL) right = right->next;
        while (left != right && left->prev != right) {
            number_left = left->index;
            number_right = right->index;
            swap(left->value, right->value);
            left->index = number_left;
            right->index = number_right;
            left = left->next;
            right = right->prev;
        }
    }

    // Output of Double list
    friend ostream& operator << (ostream& stream, const DoubleList& list);

};

ostream& operator << (ostream& stream, const DoubleList& list)
{
    DoubleList::Node* write = list.head;
    while (write != NULL) {
        stream << write->value << " ";
        write = write->next;
    }
    return stream;
}