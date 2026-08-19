/*
    Write a program to implement Queue using linkedlist.
*/
#include <iostream>

struct linkedlist {
    int data;
    linkedlist *next;
};
class stack_linkedList {
 public:
    linkedlist *front;
    linkedlist *rear;

    stack_linkedList() { front = rear = NULL; }
    void enqueue(int);
    int dequeue();
    void display();
};
void stack_linkedList::enqueue(int ele) {
	std::cerr << ">>> Entering stack_linkedList::enqueue(ele=" << ele << ")" << std::endl;
    linkedlist *temp = new linkedlist();
    temp->data = ele;
    temp->next = NULL;

    if (front == NULL)
        front = rear = temp;
    else {
        rear->next = temp;
        rear = temp;
    }
	std::cerr << "<<< Exiting stack_linkedList::enqueue(ele=" << ele << ")" << std::endl;
}
int stack_linkedList::dequeue() {
	std::cerr << ">>> Entering stack_linkedList::dequeue()" << std::endl;
    linkedlist *temp;
    int ele;
    if (front == NULL)
        std::cout << "\nStack is empty";
    else {
        temp = front;
        ele = temp->data;
		std::cerr << "stack_linkedList::dequeue(): ele → " << ele << std::endl;
        if (front == rear)  // if length of queue is 1;
            rear = rear->next;
        front = front->next;
        delete (temp);
    }
	std::cerr << "<<< Exiting stack_linkedList::dequeue()" << std::endl;
    return ele;
}
void stack_linkedList::display() {
	std::cerr << ">>> Entering stack_linkedList::display()" << std::endl;
    if (front == NULL)
        std::cout << "\nStack is empty";

    else {
        linkedlist *temp;
        temp = front;
        while (temp != NULL) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
    }
	std::cerr << "<<< Exiting stack_linkedList::display()" << std::endl;
}

int main() {
	std::cerr << ">>> Entering main()" << std::endl;
    int op, data;
    stack_linkedList ob;
    std::cout << "\n1. enqueue(Insertion) ";
    std::cout << "\n2. dequeue(Deletion)";
    std::cout << "\n3. Display";
    std::cout << "\n4. Exit";

    while (1) {
        std::cout << "\nEnter your choice ";
        std::cin >> op;
        if (op == 1) {
            std::cout << "Enter data ";
            std::cin >> data;
            ob.enqueue(data);
        } else if (op == 2)
            data = ob.dequeue();
        else if (op == 3)
            ob.display();
        else if (op == 4)
            exit(0);
        else
            std::cout << "\nWrong choice ";
    }
	std::cerr << "<<< Exiting main()" << std::endl;
    return 0;
}
