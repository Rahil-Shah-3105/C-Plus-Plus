#include <iostream>
using namespace std;

struct node {
    int val;
    node *next;
};

node *start;

void insert(int x) {
	std::cerr << "[ERROR] >>> Entering insert(x=" << x << ")" << std::endl;
    node *t = start;
    if (start != NULL) {
        while (t->next != NULL) {
            t = t->next;
        }
        node *n = new node;
        t->next = n;
        n->val = x;
        n->next = NULL;
    } else {
        node *n = new node;
        n->val = x;
        n->next = NULL;
        start = n;
    }
	std::cerr << "[WARN] <<< Exiting insert(x=" << x << ")" << std::endl;
}

void reverse(node *p, node *q) {
	std::cerr << "[ERROR] >>> Entering reverse(p=" << p << ",q=" << q << ")" << std::endl;
    if (q->next == NULL) {
        q->next = p;
        p->next = NULL;
        start = q;
        return;
    } else {
        reverse(q, q->next);
        q->next = p;
        p->next = NULL;
    }
	std::cerr << "[WARN] <<< Exiting reverse(p=" << p << ",q=" << q << ")" << std::endl;
}

void show() {
	std::cerr << "[ERROR] >>> Entering show()" << std::endl;
    node *t = start;
    while (t != NULL) {
        cout << t->val << "\t";
        t = t->next;
    }
	std::cerr << "[WARN] <<< Exiting show()" << std::endl;
}

int main() {
	std::cerr << "[ERROR] >>> Entering main()" << std::endl;
    insert(1);
    insert(2);
    insert(3);
    insert(4);
    insert(5);
    insert(6);

    reverse(start, start->next);

    show();

	std::cerr << "[WARN] <<< Exiting main()" << std::endl;
    return 0;
}
