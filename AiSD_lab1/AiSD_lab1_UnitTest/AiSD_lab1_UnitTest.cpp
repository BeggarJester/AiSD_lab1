#include "pch.h"
#include "CppUnitTest.h"
#include "../AiSD_lab1/AiSD_lab1_DoubleList.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		TEST_METHOD(DefaultConstructorTest)
		{
			DoubleList MyDoubleList;
			Assert::IsTrue(MyDoubleList.get_size() == 0);
		}
		TEST_METHOD(ConstructorWithValueTest)
		{
			DoubleList MyDoubleList(2);
			Assert::IsTrue(MyDoubleList.get_size() == 1);
			DoubleList::Node* buffer = MyDoubleList.tail;
			Assert::IsTrue(buffer->value == 2);
		}
		TEST_METHOD(DescructorTest)
		{
			DoubleList MyDoubleList;
			MyDoubleList.push_back(2);
			MyDoubleList.push_front(1);
			MyDoubleList.insert(7, 1);
			MyDoubleList.remove(1);
			Assert::IsTrue(MyDoubleList.get_size() == 2);
			MyDoubleList.~DoubleList();
			Assert::IsTrue(MyDoubleList.get_size() == 0);
		}
		TEST_METHOD(PushBackTest)
		{
			DoubleList MyDoubleList;
			Assert::IsTrue(MyDoubleList.isEmpty() == 1);
			MyDoubleList.push_back(2);
			DoubleList::Node* buffer = MyDoubleList.tail;
			Assert::IsTrue(buffer->value == 2);
			Assert::IsTrue(MyDoubleList.isEmpty() == 0);
			MyDoubleList.push_back(1);
			buffer = MyDoubleList.tail;
			Assert::IsTrue(buffer->value == 1);
		}
		TEST_METHOD(PushFrontTest)
		{
			DoubleList MyDoubleList;
			Assert::IsTrue(MyDoubleList.isEmpty() == 1);
			MyDoubleList.push_back(2);
			DoubleList::Node* buffer = MyDoubleList.head;
			Assert::IsTrue(buffer->value == 2);
			Assert::IsTrue(MyDoubleList.get_size() == 1);
			Assert::IsTrue(MyDoubleList.isEmpty() == 0);
			MyDoubleList.push_front(1);
			Assert::IsTrue(MyDoubleList.get_size() == 2);
			buffer = MyDoubleList.head;
			Assert::IsTrue(buffer->value == 1);
		}
		TEST_METHOD(PopFrontTest)
		{
			DoubleList MyDoubleList;
			Assert::IsTrue(MyDoubleList.isEmpty() == 1);
			try {
				MyDoubleList.pop_front();
			}
			catch (const invalid_argument error) {
				Assert::AreEqual("Double list is empty. First element cannot be deleted", error.what());
			}
			MyDoubleList.push_back(2);
			MyDoubleList.push_front(1);
			Assert::IsTrue(MyDoubleList.isEmpty() == 0);
			Assert::IsTrue(MyDoubleList.get_size() == 2);
			try {
				MyDoubleList.pop_front();
			}
			catch (const invalid_argument error) {
				Assert::AreEqual("Double list is empty. First element cannot be deleted", error.what());
			}
			DoubleList::Node* buffer = MyDoubleList.head;
			Assert::IsTrue(buffer->value == 2);
			Assert::IsTrue(MyDoubleList.get_size() == 1);
		}
		TEST_METHOD(PopBackTest)
		{
			DoubleList MyDoubleList;
			Assert::IsTrue(MyDoubleList.isEmpty() == 1);
			try {
				MyDoubleList.pop_back();
			}
			catch (const invalid_argument error) {
				Assert::AreEqual("Double list is empty. Last element cannot be deleted", error.what());
			}
			MyDoubleList.push_back(2);
			MyDoubleList.push_front(1);
			Assert::IsTrue(MyDoubleList.isEmpty() == 0);
			Assert::IsTrue(MyDoubleList.get_size() == 2);
			try {
				MyDoubleList.pop_back();
			}
			catch (const invalid_argument error) {
				Assert::AreEqual("Double list is empty. Last element cannot be deleted", error.what());
			}
			DoubleList::Node* buffer = MyDoubleList.head;
			Assert::IsTrue(buffer->value == 1);
			Assert::IsTrue(MyDoubleList.get_size() == 1);
		}
		TEST_METHOD(InsertTest)
		{
			DoubleList MyDoubleList;
			try {
				MyDoubleList.insert(5, 0);
			}
			catch (const out_of_range error) {
				Assert::AreEqual("Position of element is larger than maximum Double list index", error.what());
			}
			MyDoubleList.push_back(2);
			MyDoubleList.push_front(1);
			DoubleList::Node* buffer = MyDoubleList.head->next;
			Assert::IsTrue(buffer->value == 2);
			Assert::IsTrue(MyDoubleList.get_size() == 2);
			try {
				MyDoubleList.insert(7, 10);
			}
			catch (const out_of_range error) {
				Assert::AreEqual("Position of element is larger than maximum Double list index", error.what());
			}
			try {
				MyDoubleList.insert(7, 1);
			}
			catch (const out_of_range error) {
				Assert::AreEqual("Position of element is larger than maximum Double list index", error.what());
			}
			buffer = MyDoubleList.head->next;
			Assert::IsTrue(buffer->value == 7);
			buffer = MyDoubleList.tail;
			Assert::IsTrue(buffer->value == 2);
			Assert::IsTrue(MyDoubleList.get_size() == 3);
			try {
				MyDoubleList.insert(5, 0);
			}
			catch (const out_of_range error) {
				Assert::AreEqual("Position of element is larger than maximum Double list index", error.what());
			}
			Assert::IsTrue(MyDoubleList.get_size() == 4);
			buffer = MyDoubleList.head;
			Assert::IsTrue(buffer->value == 5);
		}
		TEST_METHOD(AtTest)
		{
			DoubleList MyDoubleList;
			MyDoubleList.push_back(2);
			try {
				MyDoubleList.at(5);
			}
			catch (const out_of_range error) {
				Assert::AreEqual("Position of element is out of range Double list index", error.what());
			}
			try {
				MyDoubleList.at(3);
			}
			catch (const out_of_range error) {
				Assert::AreEqual("Position of element is out of range Double list index", error.what());
			}
			Assert::IsTrue(MyDoubleList.at(0) == 2);
		}
		TEST_METHOD(RemoveTest)
		{
			DoubleList MyDoubleList;
			MyDoubleList.push_back(2);
			MyDoubleList.push_front(1);
			MyDoubleList.push_front(5);
			MyDoubleList.insert(7, 1);
			Assert::IsTrue(MyDoubleList.get_size() == 4);
			try {
				MyDoubleList.remove(5);
			}
			catch (const out_of_range error) {
				Assert::AreEqual("Position of element is out of range Double list index", error.what());
			}
			Assert::IsTrue(MyDoubleList.get_size() == 4);
			try {
				MyDoubleList.remove(3);
			}
			catch (const out_of_range error) {
				Assert::AreEqual("Position of element is out of range Double list index", error.what());
			}
			DoubleList::Node* buffer = MyDoubleList.tail;
			Assert::IsTrue(buffer->value == 1);
			buffer = MyDoubleList.head;
			Assert::IsTrue(buffer->value == 5);
			Assert::IsTrue(MyDoubleList.get_size() == 3);
			try {
				MyDoubleList.remove(0);
			}
			catch (const out_of_range error) {
				Assert::AreEqual("Position of element is out of range Double list index", error.what());
			}
			Assert::IsTrue(MyDoubleList.get_size() == 2);
			MyDoubleList.push_back(3);
			Assert::IsTrue(MyDoubleList.get_size() == 3);
			try {
				MyDoubleList.remove(1);
			}
			catch (const out_of_range error) {
				Assert::AreEqual("Position of element is out of range Double list index", error.what());
			}
			Assert::IsTrue(MyDoubleList.get_size() == 2);
			buffer = MyDoubleList.head;
			Assert::IsTrue(buffer->value == 7);
		}
		TEST_METHOD(GetSizeTest)
		{
			DoubleList MyDoubleList;
			Assert::IsTrue(MyDoubleList.get_size() == 0);
			MyDoubleList.push_back(2);
			Assert::IsTrue(MyDoubleList.get_size() == 1);
			MyDoubleList.push_front(1);
			Assert::IsTrue(MyDoubleList.get_size() == 2);
			MyDoubleList.insert(7, 1);
			Assert::IsTrue(MyDoubleList.get_size() == 3);
			MyDoubleList.remove(1);
			Assert::IsTrue(MyDoubleList.get_size() == 2);
		}
		TEST_METHOD(ClearTest)
		{
			DoubleList MyDoubleList;
			MyDoubleList.push_back(2);
			MyDoubleList.push_front(1);
			MyDoubleList.insert(7, 1);
			MyDoubleList.remove(1);
			Assert::IsTrue(MyDoubleList.get_size() == 2);
			MyDoubleList.clear();
			Assert::IsTrue(MyDoubleList.get_size() == 0);
		}
		TEST_METHOD(SetTest)
		{
			DoubleList MyDoubleList;
			MyDoubleList.push_back(2);
			MyDoubleList.push_front(1);
			MyDoubleList.insert(7, 1);
			try {
				MyDoubleList.set(0, 10);
			}
			catch (const out_of_range error) {
				Assert::AreEqual("Position of element is out of range Double list index", error.what());
			}
			try {
				MyDoubleList.set(1, 11);
			}
			catch (const out_of_range error) {
				Assert::AreEqual("Position of element is out of range Double list index", error.what());
			}
			try {
				MyDoubleList.set(2, 12);
			}
			catch (const out_of_range error) {
				Assert::AreEqual("Position of element is out of range Double list index", error.what());
			}
			try {
				MyDoubleList.set(1000, 17);
			}
			catch (const out_of_range error) {
				Assert::AreEqual("Position of element is out of range Double list index", error.what());
			}
			DoubleList::Node* buffer = MyDoubleList.head;
			Assert::IsTrue(buffer->value == 10);
			buffer = buffer->next;
			Assert::IsTrue(buffer->value == 11);
			buffer = MyDoubleList.tail;
			Assert::IsTrue(buffer->value == 12);
		}
		TEST_METHOD(IsEmptyTest)
		{
			DoubleList MyDoubleList;
			Assert::IsTrue(MyDoubleList.isEmpty() == 1);
			MyDoubleList.push_back(2);
			Assert::IsTrue(MyDoubleList.isEmpty() == 0);
		}
		TEST_METHOD(OutputTest)
		{
			DoubleList MyDoubleList;
			MyDoubleList.push_back(2);
			MyDoubleList.push_front(1);
			MyDoubleList.insert(7, 1);
			stringstream output;
			output << MyDoubleList;
			Assert::IsTrue(output.str() == "1 7 2 ");
		}
		TEST_METHOD(ReverseTest)
		{
			DoubleList MyDoubleList;
			MyDoubleList.push_back(2);
			MyDoubleList.push_front(1);
			MyDoubleList.insert(7, 1);
			MyDoubleList.reverse();
			stringstream output;
			output << MyDoubleList;
			Assert::IsTrue(output.str() == "2 7 1 ");
		}

	};
}
