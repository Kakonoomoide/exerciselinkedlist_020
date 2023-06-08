#include <iostream>
#include <string>
using namespace std;
class Node {
public:
	int rollNumber;
	string name;
	Node* next;
};

class CircularLinkedList {
private:
	Node* LAST;
public:
	CircularLinkedList() {
		LAST = NULL;
	}
	void addNode();
	bool search(int rollno, Node** previous, Node** current);
	bool listEmpty();
	bool delNode(int rollNO);
	void traverse();
	void hapus();
};


void CircularLinkedList::addNode() {//write your answer here
	int number;
	string nama;
	Node* nodeBaru = new Node(); // alocate memory for new node

	cout << "input your rollnumber  : "; //input
	cin >> number;
	cout << "input your name	    : ";
	cin >> nama;

	nodeBaru->rollNumber = number;
	nodeBaru->name = nama;

	if (LAST == NULL || number <= LAST->rollNumber) { 
		if (LAST != NULL && number == LAST->rollNumber) {
			cout << "\nNim sudah ada!" << endl;		// check if number already exist
			return;
		}
		nodeBaru->next = LAST ;
		if (LAST != NULL)
			LAST->next = nodeBaru;
		LAST = nodeBaru;
		return;
	}

	Node* rizki = LAST;
	Node* ramadan = LAST;


	//while ((rizki != NULL) && (number >= rizki->rollNumber)) {
	//	if (number == rizki->rollNumber) {
	//		cout << "\nNim sudah ada!" << endl;
	//		return;
	//	}
	//	ramadan = rizki;
	//	rizki = rizki->next;
	//}
	//nodeBaru->next = rizki;
	//ramadan->next = nodeBaru;

	while (rizki->next != NULL && number > rizki->next->rollNumber)
		rizki = rizki->next;

	if (rizki->next != NULL && number == rizki->next->rollNumber) { //memeriksa bila ada duplicate number
		cout << "\nDuplicate roll nummbers not allowed" << endl;
		return;
	}

	nodeBaru->next = LAST->next;

	if (rizki->next != NULL)
		rizki->next->next = nodeBaru;
	rizki->next = nodeBaru;

	//cout << rizki->rollNumber << " " << rizki->name << endl;
	//rizki = rizki->next;
}

bool CircularLinkedList::search(int rollno, Node** previous, Node** current) {
	*previous = LAST->next;
	*current = LAST->next;
	while (*current != LAST) {
		if (rollno == (*current)->rollNumber) {
			return true;
		}
		*previous = *current;
		*current = (*current)->next;
	}
	if (rollno == LAST->rollNumber) {
		return true;
	}
	else {
		return false;
	}
}

bool CircularLinkedList::listEmpty() {
	return LAST == NULL;
}

bool CircularLinkedList::delNode(int rollNO) { //write your answer here
	Node* next, * current;
	LAST = current = NULL;

	if (search(rollNO ,&LAST , &current) == false)
		return false;

	if (current->next != NULL)
		current->next->next = LAST;
	if (LAST != NULL)
		LAST->next = current->next;
	else
		LAST = current->next;

	delete current;
	return true;
}

void CircularLinkedList::hapus() { // add methode hapus
	if (listEmpty())
		cout << "\nlist is empty" << endl;

	cout << "\nEnter the roll number of the student whose record is to be deleted: ";
	int rollNo;
	cin >> rollNo;
	cout << endl;

	if (CircularLinkedList::delNode(rollNo) == false)
		cout << "Record not found" << endl;
	else
		cout << "Record with roll number " << rollNo << " deleted" << endl;
}

void CircularLinkedList::traverse() {
	if (listEmpty()) {
		cout << "\nList is empty\n";
	}
	else {
		cout << "\nRecords in the list are:\n";
		Node* currentNode = LAST->next;
		while (currentNode != LAST) {
			cout << currentNode->rollNumber << " " << currentNode->name << endl;
			currentNode = currentNode->next;
		}
		cout << LAST->rollNumber << " " << LAST->name << endl;
	}
}

int main() {
	CircularLinkedList obj;
	while (true) {
		try {
			cout << "\nMenu" << endl;
			cout << "1. Add a record to the list" << endl;
			cout << "2. Delete a record from the list" << endl;
			cout << "3. View all the records in the list" << endl;
			cout << "4. Exit" << endl;
			cout << "\nEnter your choice (1-4): ";
			char ch;
			cin >> ch;
			switch (ch) {
			case '1': {
				obj.addNode();
				break;
			}
			case '2': {
				obj.hapus();
				break;
			}
			case '3': {
				obj.traverse();
				break;
			}
			case '4': {
				return 0;
			}
			default: {
				cout << "Invalid option" << endl;
				break;
			}
			}
		}
		catch (exception& e) {
			cout << e.what() << endl;
		}
	}
	return 0;
}