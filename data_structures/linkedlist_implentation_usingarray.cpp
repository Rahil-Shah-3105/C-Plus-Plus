/**
 * \file
 * \brief Linked list implementation using Arrays
 *
 * The difference between the pointer implementation of linked list and array
 * implementation of linked list:
 * 1. The NULL is represented by -1;
 * 2. Limited size. (in the following case it is 100 nodes at max). But we can
 * reuse the nodes that are to be deleted by again linking it bacj to the list.
 */

#include <iostream>

struct Node {
    int data;
    int next;
};

Node AvailArray[100];  ///< array that will act as nodes of a linked list.

int head = -1;
int avail = 0;
void initialise_list() {
	std::cerr << ">>> Entering initialise_list()" << std::endl;
    for (int i = 0; i <= 98; i++) {
        AvailArray[i].next = i + 1;
    }
    AvailArray[99].next = -1;  // indicating the end of the linked list.
	std::cerr << "<<< Exiting initialise_list()" << std::endl;
}

/** This will return the index of the first free node present in the avail list
 */
int getnode() {
	std::cerr << ">>> Entering getnode()" << std::endl;
    int NodeIndexToBeReturned = avail;
    avail = AvailArray[avail].next;
	std::cerr << "getnode(): avail → " << avail << std::endl;
	std::cerr << "<<< Exiting getnode()" << std::endl;
    return NodeIndexToBeReturned;
}

/** This function when called will delete the node with
 * the index presented as an argument, and will put
 * back that node into the array.
 */
void freeNode(int nodeToBeDeleted) {
	std::cerr << ">>> Entering freeNode(nodeToBeDeleted=" << nodeToBeDeleted << ")" << std::endl;
    AvailArray[nodeToBeDeleted].next = avail;
    avail = nodeToBeDeleted;
	std::cerr << "freeNode(nodeToBeDeleted=" << nodeToBeDeleted << "): avail → " << avail << std::endl;
	std::cerr << "<<< Exiting freeNode(nodeToBeDeleted=" << nodeToBeDeleted << ")" << std::endl;
}

/** The function will insert the given data
 * into the front of the linked list.
 */
void insertAtTheBeginning(int data) {
	std::cerr << ">>> Entering insertAtTheBeginning(data=" << data << ")" << std::endl;
    int newNode = getnode();
    AvailArray[newNode].data = data;
	std::cerr << "insertAtTheBeginning(data=" << data << "): newNode → " << newNode << std::endl;
    AvailArray[newNode].next = head;
    head = newNode;
	std::cerr << "insertAtTheBeginning(data=" << data << "): head → " << head << std::endl;
	std::cerr << "<<< Exiting insertAtTheBeginning(data=" << data << ")" << std::endl;
}

void insertAtTheEnd(int data) {
	std::cerr << ">>> Entering insertAtTheEnd(data=" << data << ")" << std::endl;
    int newNode = getnode();
    int temp = head;
	std::cerr << "insertAtTheEnd(data=" << data << "): newNode → " << newNode << std::endl;
    while (AvailArray[temp].next != -1) {
        temp = AvailArray[temp].next;
    }
    // temp is now pointing to the end node.
    AvailArray[newNode].data = data;
    AvailArray[newNode].next = -1;
    AvailArray[temp].next = newNode;
	std::cerr << "<<< Exiting insertAtTheEnd(data=" << data << ")" << std::endl;
}

void display() {
	std::cerr << ">>> Entering display()" << std::endl;
    int temp = head;
    while (temp != -1) {
        std::cout << AvailArray[temp].data << "->";
        temp = AvailArray[temp].next;
    }
    std::cout << "-1" << std::endl;
	std::cerr << "<<< Exiting display()" << std::endl;
}

/** Main function */
int main() {
	std::cerr << ">>> Entering main()" << std::endl;
    initialise_list();
    int x, y, z;
    for (;;) {
        std::cout << "1. Insert At The Beginning" << std::endl;
        std::cout << "2. Insert At The End" << std::endl;
        std::cout << "3. Display" << std::endl;
        std::cout << "4.Exit" << std::endl;
        std::cout << "Enter Your choice" << std::endl;
        std::cin >> z;
        switch (z) {
        case 1:
            std::cout << "Enter the number you want to enter" << std::endl;
            std::cin >> x;
            insertAtTheBeginning(x);
            break;
        case 2:
            std::cout << "Enter the number you want to enter" << std::endl;
            std::cin >> y;
            insertAtTheEnd(y);
            break;
        case 3:
            std::cout
                << "The linked list contains the following element in order"
                << std::endl;
            display();
            break;
        case 4:
            return 0;
        default:
            std::cout << "The entered choice is not correct" << std::endl;
        }
    }

	std::cerr << "<<< Exiting main()" << std::endl;
    return 0;
}
