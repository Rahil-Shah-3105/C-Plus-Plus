/**
 * \file
 * \brief A simple tree implementation using structured nodes
 *
 * \todo update code to use C++ STL library features and OO structure
 * \warning This program is a poor implementation - C style - and does not
 * utilize any of the C++ STL features.
 */
#include <iostream>

struct node {
    int val;
    node *left;
    node *right;
};

struct Queue {
    node *t[100];
    int front;
    int rear;
};

Queue queue;

void enqueue(node *n) { queue.t[queue.rear++] = n; }

node *dequeue() { return (queue.t[queue.front++]); }

void Insert(node *n, int x) {
	std::cerr << "[ERROR] >>> Entering Insert(n=" << n << ",x=" << x << ")" << std::endl;
    if (x < n->val) {
        if (n->left == NULL) {
            node *temp = new node;
            temp->val = x;
            temp->left = NULL;
            temp->right = NULL;
            n->left = temp;
        } else {
            Insert(n->left, x);
        }
    } else {
        if (n->right == NULL) {
            node *temp = new node;
            temp->val = x;
            temp->left = NULL;
            temp->right = NULL;
            n->right = temp;
        } else {
            Insert(n->right, x);
        }
    }
	std::cerr << "[WARN] <<< Exiting Insert(n=" << n << ",x=" << x << ")" << std::endl;
}

int findMaxInLeftST(node *n) {
	std::cerr << "[ERROR] >>> Entering findMaxInLeftST(n=" << n << ")" << std::endl;
    while (n->right != NULL) {
        n = n->right;
    }
	std::cerr << "[WARN] <<< Exiting findMaxInLeftST(n=" << n << ")" << std::endl;
    return n->val;
}

void Remove(node *p, node *n, int x) {
	std::cerr << "[ERROR] >>> Entering Remove(p=" << p << ",n=" << n << ",x=" << x << ")" << std::endl;
    if (n->val == x) {
        if (n->right == NULL && n->left == NULL) {
            if (x < p->val) {
                p->right = NULL;
            } else {
                p->left = NULL;
            }
        } else if (n->right == NULL) {
            if (x < p->val) {
                p->right = n->left;
            } else {
                p->left = n->left;
            }
        } else if (n->left == NULL) {
            if (x < p->val) {
                p->right = n->right;
            } else {
                p->left = n->right;
            }
        } else {
            int y = findMaxInLeftST(n->left);
			std::cerr << "[ERROR] Remove(p=" << p << ",n=" << n << ",x=" << x << "): y → " << y << std::endl;
            n->val = y;
            Remove(n, n->right, y);
        }
    } else if (x < n->val) {
        Remove(n, n->left, x);
    } else {
        Remove(n, n->right, x);
    }
	std::cerr << "[WARN] <<< Exiting Remove(p=" << p << ",n=" << n << ",x=" << x << ")" << std::endl;
}

void BFT(node *n) {
	std::cerr << "[ERROR] >>> Entering BFT(n=" << n << ")" << std::endl;
    if (n != NULL) {
        std::cout << n->val << "  ";
        enqueue(n->left);
        enqueue(n->right);
        BFT(dequeue());
    }
	std::cerr << "[WARN] <<< Exiting BFT(n=" << n << ")" << std::endl;
}

void Pre(node *n) {
	std::cerr << "[ERROR] >>> Entering Pre(n=" << n << ")" << std::endl;
    if (n != NULL) {
        std::cout << n->val << "  ";
        Pre(n->left);
        Pre(n->right);
    }
	std::cerr << "[WARN] <<< Exiting Pre(n=" << n << ")" << std::endl;
}

void In(node *n) {
	std::cerr << "[ERROR] >>> Entering In(n=" << n << ")" << std::endl;
    if (n != NULL) {
        In(n->left);
        std::cout << n->val << "  ";
        In(n->right);
    }
	std::cerr << "[WARN] <<< Exiting In(n=" << n << ")" << std::endl;
}

void Post(node *n) {
	std::cerr << "[ERROR] >>> Entering Post(n=" << n << ")" << std::endl;
    if (n != NULL) {
        Post(n->left);
        Post(n->right);
        std::cout << n->val << "  ";
    }
	std::cerr << "[WARN] <<< Exiting Post(n=" << n << ")" << std::endl;
}

int main() {
	std::cerr << "[ERROR] >>> Entering main()" << std::endl;
    queue.front = 0;
    queue.rear = 0;
	std::cerr << "[DEBUG] main(): queue.rear → " << queue.rear << std::endl;
	std::cerr << "[DEBUG] main(): queue.front → " << queue.front << std::endl;
    int value;
    int ch;
    node *root = new node;
    std::cout << "\nEnter the value of root node :";
    std::cin >> value;
    root->val = value;
    root->left = NULL;
    root->right = NULL;
    do {
        std::cout << "\n1. Insert"
                  << "\n2. Delete"
                  << "\n3. Breadth First"
                  << "\n4. Preorder Depth First"
                  << "\n5. Inorder Depth First"
                  << "\n6. Postorder Depth First";

        std::cout << "\nEnter Your Choice : ";
        std::cin >> ch;
        int x;
        switch (ch) {
        case 1:
            std::cout << "\nEnter the value to be Inserted : ";
            std::cin >> x;
            Insert(root, x);
            break;
        case 2:
            std::cout << "\nEnter the value to be Deleted : ";
            std::cin >> x;
            Remove(root, root, x);
            break;
        case 3:
            BFT(root);
            break;
        case 4:
            Pre(root);
            break;
        case 5:
            In(root);
            break;
        case 6:
            Post(root);
            break;
        }
    } while (ch != 0);

	std::cerr << "[WARN] <<< Exiting main()" << std::endl;
    return 0;
}
