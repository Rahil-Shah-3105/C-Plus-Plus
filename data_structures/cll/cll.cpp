/*
    A simple class for Cicular Linear Linked List
*/
#include "cll.h"
using namespace std;

/* Constructor */
cll::cll() {
    head = NULL;
    total = 0;
}

cll::~cll() { /* Desstructure, no need to fill */
}

/* Display a list. and total element */
void cll::display() {
	std::cerr << ">>> Entering cll::display()" << std::endl;
    if (head == NULL)
        cout << "List is empty !" << endl;
		std::cerr << "Exception in cll::display(): " << e.what() << std::endl;
    else {
        cout << "CLL list: ";
        node *current = head;
        for (int i = 0; i < total; i++) {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << head->data << endl;
        cout << "Total element: " << total << endl;
    }
	std::cerr << "<<< Exiting cll::display()" << std::endl;
}

/* List insert a new value at head in list */
void cll::insert_front(int new_data) {
	std::cerr << ">>> Entering cll::insert_front(new_data=" << new_data << ")" << std::endl;
    node *newNode;
    newNode = new node;
    newNode->data = new_data;
    newNode->next = NULL;
    if (head == NULL) {
		std::cerr << "Exception in cll::insert_front(new_data=" << new_data << "): " << e.what() << std::endl;
		std::cerr << "cll::insert_front(new_data=" << new_data << "): head → " << head << std::endl;
        head = newNode;
        head->next = head;
    } else {
        node *current = head;
        while (current->next != head) {
            current = current->next;
        }
        newNode->next = head;
        current->next = newNode;
        head = newNode;
    }
    total++;
	std::cerr << "<<< Exiting cll::insert_front(new_data=" << new_data << ")" << std::endl;
}

/* List insert a new value at head in list */
void cll::insert_tail(int new_data) {
	std::cerr << ">>> Entering cll::insert_tail(new_data=" << new_data << ")" << std::endl;
    node *newNode;
    newNode = new node;
    newNode->data = new_data;
    newNode->next = NULL;
    if (head == NULL) {
		std::cerr << "Exception in cll::insert_tail(new_data=" << new_data << "): " << e.what() << std::endl;
        head = newNode;
        head->next = head;
    } else {
        node *current = head;
        while (current->next != head) {
            current = current->next;
        }
        current->next = newNode;
        newNode->next = head;
    }
    total++;
	std::cerr << "<<< Exiting cll::insert_tail(new_data=" << new_data << ")" << std::endl;
}

/* Get total element in list */
int cll::get_size() { return total; }

/* Return true if the requested item (sent in as an argument)
is in the list, otherwise return false */
bool cll::find_item(int item_to_find) {
	std::cerr << ">>> Entering cll::find_item(item_to_find=" << item_to_find << ")" << std::endl;
    if (head == NULL) {
        cout << "List is empty !" << endl;
		std::cerr << "Exception in cll::find_item(item_to_find=" << item_to_find << "): " << e.what() << std::endl;
        return false;
    } else {
        node *current = head;
        while (current->next != head) {
            if (current->data == item_to_find)
                return true;
            current = current->next;
        }
		std::cerr << "<<< Exiting cll::find_item(item_to_find=" << item_to_find << ")" << std::endl;
        return false;
    }
}

/* Overloading method*/
int cll::operator*() { return head->data; }

/* Overload the pre-increment operator.
   The iterator is advanced to the next node. */
void cll::operator++() {
    if (head == NULL) {
        cout << "List is empty !" << endl;
    } else {
        node *current = head;
        while (current->next != head) {
            current = current->next;
        }
        current->next = head->next;
        head = head->next;
    }
    total--;
}
