#include <cstdio>
#include <cstdlib>
#include <iostream>

struct node {
    int val;
    node *prev;
    node *next;
} * start;

class double_linked_list {
 public:
    double_linked_list() { start = NULL; }
    void insert(int x);
    void remove(int x);
    void search(int x);
    void show();
    void reverseShow();
};

void double_linked_list::insert(int x) {
	std::cerr << ">>> Entering double_linked_list::insert(x=" << x << ")" << std::endl;
    node *t = start;
    if (start != NULL) {
        while (t->next != NULL) {
            t = t->next;
        }
        node *n = new node;
        t->next = n;
        n->prev = t;
        n->val = x;
        n->next = NULL;
    } else {
        node *n = new node;
        n->val = x;
        n->prev = NULL;
        n->next = NULL;
        start = n;
		std::cerr << "double_linked_list::insert(x=" << x << "): start → " << start << std::endl;
    }
	std::cerr << "<<< Exiting double_linked_list::insert(x=" << x << ")" << std::endl;
}

void double_linked_list::remove(int x) {
	std::cerr << ">>> Entering double_linked_list::remove(x=" << x << ")" << std::endl;
    node *t = start;
    while (t != NULL && t->val != x) {
        t = t->next;
    }
    if (t == NULL) {
        return;
    }
    if (t->prev == NULL) {
        if (t->next == NULL) {
            start = NULL;
        } else {
            start = t->next;
            start->prev = NULL;
        }
    } else if (t->next == NULL) {
        t->prev->next = NULL;
    } else {
        t->prev->next = t->next;
        t->next->prev = t->prev;
    }
    delete t;
	std::cerr << "<<< Exiting double_linked_list::remove(x=" << x << ")" << std::endl;
}

void double_linked_list::search(int x) {
	std::cerr << ">>> Entering double_linked_list::search(x=" << x << ")" << std::endl;
    node *t = start;
    int found = 0;
	std::cerr << "double_linked_list::search(x=" << x << "): found → " << found << std::endl;
    while (t != NULL) {
        if (t->val == x) {
            std::cout << "\nFound";
            found = 1;
            break;
        }
        t = t->next;
    }
    if (found == 0) {
        std::cout << "\nNot Found";
    }
	std::cerr << "<<< Exiting double_linked_list::search(x=" << x << ")" << std::endl;
}

void double_linked_list::show() {
	std::cerr << ">>> Entering double_linked_list::show()" << std::endl;
    node *t = start;
    while (t != NULL) {
        std::cout << t->val << "\t";
        t = t->next;
    }
	std::cerr << "<<< Exiting double_linked_list::show()" << std::endl;
}

void double_linked_list::reverseShow() {
	std::cerr << ">>> Entering double_linked_list::reverseShow()" << std::endl;
    node *t = start;
    while (t != NULL && t->next != NULL) {
		std::cerr << "double_linked_list::reverseShow(): t → " << t << std::endl;
        t = t->next;
    }
    while (t != NULL) {
        std::cout << t->val << "\t";
        t = t->prev;
    }
	std::cerr << "<<< Exiting double_linked_list::reverseShow()" << std::endl;
}

int main() {
	std::cerr << ">>> Entering main()" << std::endl;
    int choice, x;
    double_linked_list ob;
    do {
        std::cout << "\n1. Insert";
        std::cout << "\n2. Delete";
        std::cout << "\n3. Search";
        std::cout << "\n4. Forward print";
        std::cout << "\n5. Reverse print";
        std::cout << "\n\nEnter you choice : ";
        std::cin >> choice;
        switch (choice) {
        case 1:
            std::cout << "\nEnter the element to be inserted : ";
            std::cin >> x;
            ob.insert(x);
            break;
        case 2:
            std::cout << "\nEnter the element to be removed : ";
            std::cin >> x;
            ob.remove(x);
            break;
        case 3:
            std::cout << "\nEnter the element to be searched : ";
            std::cin >> x;
            ob.search(x);
            break;
        case 4:
            ob.show();
            break;
        case 5:
            ob.reverseShow();
            break;
        }
    } while (choice != 0);
	std::cerr << "<<< Exiting main()" << std::endl;
    return 0;
}
