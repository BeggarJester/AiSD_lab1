#include "AiSD_lab1_DoubleList.h"

using namespace std;

int main()
{
	cout << "Create a new emrty Double List: \n";
	DoubleList MyDoubleList;
	cout << MyDoubleList;
	cout << "Add '2' to the end of Double List: \n";
	MyDoubleList.push_back(2);
	cout << MyDoubleList;
	cout << "\n Try to get second element of Double List: \n";
	try {
		MyDoubleList.at(2);
	}
	catch (const out_of_range error) {
		cout << error.what();
	}
	cout << "Add '1' to the begin and '3' to the end of Double List and try again: \n";
	MyDoubleList.push_front(1);
	MyDoubleList.push_back(3);
	cout << MyDoubleList << '\n';
	try {
		MyDoubleList.at(2);
	}
	catch (const out_of_range error) {
		cout << error.what();
	}
	cout << "\n Check the size of Double List: \n";
	cout << MyDoubleList.get_size();
	cout << "\n Insert '7' at first position: \n";
	MyDoubleList.insert(7, 1);
	cout << MyDoubleList;
	cout << "\n Set '19' at swcond position: \n";
	MyDoubleList.set(2, 19);
	cout << MyDoubleList;
	cout << "\n Reverse the Double List: \n";
	MyDoubleList.reverse();
	cout << MyDoubleList;
	cout << "\n Remove element at first position: \n";
	MyDoubleList.remove(1);
	cout << MyDoubleList;
	cout << "\n Check empty of Double List: \n 0 is not empty \n 1 is empty \n";
	cout << MyDoubleList.isEmpty();
	cout << "\n Clear the Double List: \n";
	MyDoubleList.clear();
	cout << "\n Check empty of Double List: \n 0 is not empty \n 1 is empty \n";
	cout << MyDoubleList.isEmpty();
}


