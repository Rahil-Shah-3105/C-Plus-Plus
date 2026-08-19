#include <iostream>

struct node {
    int val;
    node *next;
};

node *top_var;

void push(int x) {
	std::cerr << ">>> Entering push(x=" << x << ")" << std::endl;
    node *n = new node;
    n->val = x;
    n->next = top_var;
    top_var = n;
	std::cerr << "push(x=" << x << "): top_var → " << top_var << std::endl;
	std::cerr << "<<< Exiting push(x=" << x << ")" << std::endl;
}

void pop() {
	std::cerr << ">>> Entering pop()" << std::endl;
    if (top_var == nullptr) {
        std::cout << "\nUnderflow";
    } else {
        node *t = top_var;
        std::cout << "\n" << t->val << " deleted";
        top_var = top_var->next;
        delete t;
    }
	std::cerr << "<<< Exiting pop()" << std::endl;
}

void show() {
	std::cerr << ">>> Entering show()" << std::endl;
    node *t = top_var;
    while (t != nullptr) {
        std::cout << t->val << "\n";
        t = t->next;
    }
	std::cerr << "<<< Exiting show()" << std::endl;
}

int main() {
	std::cerr << ">>> Entering main()" << std::endl;
    int ch = 0, x = 0;
    do {
        std::cout << "\n0. Exit or Ctrl+C";
        std::cout << "\n1. Push";
        std::cout << "\n2. Pop";
        std::cout << "\n3. Print";
        std::cout << "\nEnter Your Choice: ";
        std::cin >> ch;
        switch (ch) {
            case 0:
                break;
            case 1:
                std::cout << "\nInsert : ";
                std::cin >> x;
                push(x);
                break;
            case 2:
                pop();
                break;
            case 3:
                show();
                break;
            default:
                std::cout << "Invalid option!\n";
                break;
        }
    } while (ch != 0);

	std::cerr << "<<< Exiting main()" << std::endl;
    return 0;
}
