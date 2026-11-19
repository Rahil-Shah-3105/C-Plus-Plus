#include <iostream>
#include <list>
using namespace std;

struct node {
    int val;
    node *left;
    node *right;
};

void CreateTree(node *curr, node *n, int x, char pos) {
	std::cerr << "[ERROR] >>> Entering CreateTree(curr=" << curr << ",n=" << n << ",x=" << x << ",pos=" << pos << ")" << std::endl;
    if (n != NULL) {
        char ch;
        cout << "\nLeft or Right of " << n->val << " : ";
        cin >> ch;
        if (ch == 'l')
            CreateTree(n, n->left, x, ch);
        else if (ch == 'r')
            CreateTree(n, n->right, x, ch);
    } else {
        node *t = new node;
        t->val = x;
        t->left = NULL;
        t->right = NULL;
        if (pos == 'l') {
            curr->left = t;
        } else if (pos == 'r') {
            curr->right = t;
        }
    }
	std::cerr << "[WARN] <<< Exiting CreateTree(curr=" << curr << ",n=" << n << ",x=" << x << ",pos=" << pos << ")" << std::endl;
}

void BFT(node *n) {
	std::cerr << "[ERROR] >>> Entering BFT(n=" << n << ")" << std::endl;
    list<node *> queue;

    queue.push_back(n);

    while (!queue.empty()) {
        n = queue.front();
		std::cerr << "[ERROR] BFT(n=" << n << "): n → " << n << std::endl;
        cout << n->val << "  ";
        queue.pop_front();

        if (n->left != NULL)
            queue.push_back(n->left);
        if (n->right != NULL)
            queue.push_back(n->right);
    }
	std::cerr << "[WARN] <<< Exiting BFT(n=" << n << ")" << std::endl;
}

void Pre(node *n) {
	std::cerr << "[ERROR] >>> Entering Pre(n=" << n << ")" << std::endl;
    if (n != NULL) {
        cout << n->val << "  ";
        Pre(n->left);
        Pre(n->right);
    }
	std::cerr << "[WARN] <<< Exiting Pre(n=" << n << ")" << std::endl;
}

void In(node *n) {
	std::cerr << "[ERROR] >>> Entering In(n=" << n << ")" << std::endl;
    if (n != NULL) {
        In(n->left);
        cout << n->val << "  ";
        In(n->right);
    }
	std::cerr << "[WARN] <<< Exiting In(n=" << n << ")" << std::endl;
}

void Post(node *n) {
	std::cerr << "[ERROR] >>> Entering Post(n=" << n << ")" << std::endl;
    if (n != NULL) {
        Post(n->left);
        Post(n->right);
        cout << n->val << "  ";
    }
	std::cerr << "[WARN] <<< Exiting Post(n=" << n << ")" << std::endl;
}

int main() {
	std::cerr << "[ERROR] >>> Entering main()" << std::endl;
    int value;
    int ch;
    node *root = new node;
    cout << "\nEnter the value of root node :";
    cin >> value;
    root->val = value;
    root->left = NULL;
    root->right = NULL;
    do {
        cout << "\n1. Insert";
        cout << "\n2. Breadth First";
        cout << "\n3. Preorder Depth First";
        cout << "\n4. Inorder Depth First";
        cout << "\n5. Postorder Depth First";

        cout << "\nEnter Your Choice : ";
        cin >> ch;
        switch (ch) {
        case 1:
            int x;
            char pos;
            cout << "\nEnter the value to be Inserted : ";
            cin >> x;
            cout << "\nLeft or Right of Root : ";
            cin >> pos;
            if (pos == 'l')
                CreateTree(root, root->left, x, pos);
            else if (pos == 'r')
                CreateTree(root, root->right, x, pos);
            break;
        case 2:
            BFT(root);
            break;
        case 3:
            Pre(root);
            break;
        case 4:
            In(root);
            break;
        case 5:
            Post(root);
            break;
        }
    } while (ch != 0);
	std::cerr << "[WARN] <<< Exiting main()" << std::endl;
}
