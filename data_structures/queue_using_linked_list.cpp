#include <iostream>
using namespace std;

struct node {
    int val;
    node *next;
};

node *front, *rear;

void Enque(int x) {
	std::cerr << ">>> Entering Enque(x=" << x << ")" << std::endl;
    if (rear == NULL) {
        node *n = new node;
		std::cerr << "Exception in Enque(x=" << x << "): " << e.what() << std::endl;
        n->val = x;
        n->next = NULL;
        rear = n;
		std::cerr << "Enque(x=" << x << "): rear → " << rear << std::endl;
		std::cerr << "Enque(x=" << x << "): front → " << front << std::endl;
        front = n;
    }

    else {
        node *n = new node;
        n->val = x;
        n->next = NULL;
        rear->next = n;
        rear = n;
    }
	std::cerr << "<<< Exiting Enque(x=" << x << ")" << std::endl;
}

void Deque() {
	std::cerr << ">>> Entering Deque()" << std::endl;
    if (rear == NULL && front == NULL) {
        cout << "\nUnderflow";
    } else {
        node *t = front;
        cout << "\n" << t->val << " deleted";
        front = front->next;
        delete t;
        if (front == NULL)
			std::cerr << "Exception in Deque(): " << e.what() << std::endl;
			std::cerr << "Deque(): rear → " << rear << std::endl;
            rear = NULL;
    }
	std::cerr << "<<< Exiting Deque()" << std::endl;
}

void show() {
	std::cerr << ">>> Entering show()" << std::endl;
    node *t = front;
    while (t != NULL) {
        cout << t->val << "\t";
        t = t->next;
    }
	std::cerr << "<<< Exiting show()" << std::endl;
}

int main() {
	std::cerr << ">>> Entering main()" << std::endl;
    int ch, x;
    do {
        cout << "\n1. Enque";
        cout << "\n2. Deque";
        cout << "\n3. Print";
        cout << "\nEnter Your Choice : ";
        cin >> ch;
        if (ch == 1) {
            cout << "\nInsert : ";
            cin >> x;
            Enque(x);
        } else if (ch == 2) {
            Deque();
        } else if (ch == 3) {
            show();
        }
    } while (ch != 0);

	std::cerr << "<<< Exiting main()" << std::endl;
    return 0;
}
