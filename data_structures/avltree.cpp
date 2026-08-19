/**
 * \file
 * \brief A simple tree implementation using nodes
 *
 * \todo update code to use C++ STL library features and OO structure
 * \warning This program is a poor implementation and does not utilize any of
 * the C++ STL features.
 */
#include <algorithm>  /// for std::max
#include <iostream>   /// for std::cout
#include <queue>      /// for std::queue

using node = struct node {
    int data;
    int height;
    struct node *left;
    struct node *right;
};

/**
 * @brief creates and returns a new node
 * @param[in] data value stored in the node
 * @return newly created node
 */
node *createNode(int data) {
	std::cerr << ">>> Entering createNode(data=" << data << ")" << std::endl;
    node *nn = new node();
    nn->data = data;
    nn->height = 0;
    nn->left = nullptr;
    nn->right = nullptr;
	std::cerr << "<<< Exiting createNode(data=" << data << ")" << std::endl;
    return nn;
}

/**
 * @param[in] root the root of the tree
 * @return height of tree
 */
int height(node *root) {
	std::cerr << ">>> Entering height(root=" << root << ")" << std::endl;
    if (root == nullptr) {
	std::cerr << "<<< Exiting height(root=" << root << ")" << std::endl;
        return 0;
    }
    return 1 + std::max(height(root->left), height(root->right));
}

/**
 * @param[in] root of the tree
 * @return difference between height of left and right subtree
 */
int getBalance(node *root) { return height(root->left) - height(root->right); }

/**
 * @param root of the tree to be rotated
 * @return node after right rotation
 */
node *rightRotate(node *root) {
	std::cerr << ">>> Entering rightRotate(root=" << root << ")" << std::endl;
    node *t = root->left;
    node *u = t->right;
    t->right = root;
    root->left = u;
	std::cerr << "<<< Exiting rightRotate(root=" << root << ")" << std::endl;
    return t;
}

/**
 * @param root of the tree to be rotated
 * @return node after left rotation
 */
node *leftRotate(node *root) {
	std::cerr << ">>> Entering leftRotate(root=" << root << ")" << std::endl;
    node *t = root->right;
    node *u = t->left;
    t->left = root;
    root->right = u;
	std::cerr << "<<< Exiting leftRotate(root=" << root << ")" << std::endl;
    return t;
}

/**
 * @param root of the tree
 * @returns node with minimum value in the tree
 */
node *minValue(node *root) {
	std::cerr << ">>> Entering minValue(root=" << root << ")" << std::endl;
    if (root->left == nullptr) {
	std::cerr << "<<< Exiting minValue(root=" << root << ")" << std::endl;
        return root;
    }
    return minValue(root->left);
}

/**
 * @brief inserts a new element into AVL tree
 * @param root of the tree
 * @param[in] item the element to be insterted into the tree
 * @return root of the updated tree
 */
node *insert(node *root, int item) {
	std::cerr << ">>> Entering insert(root=" << root << ",item=" << item << ")" << std::endl;
    if (root == nullptr) {
        return createNode(item);
    }
    if (item < root->data) {
        root->left = insert(root->left, item);
    } else {
        root->right = insert(root->right, item);
    }
    int b = getBalance(root);
	std::cerr << "insert(root=" << root << ",item=" << item << "): b → " << b << std::endl;
    if (b > 1) {
        if (getBalance(root->left) < 0) {
            root->left = leftRotate(root->left);  // Left-Right Case
        }
        return rightRotate(root);  // Left-Left Case
    } else if (b < -1) {
        if (getBalance(root->right) > 0) {
            root->right = rightRotate(root->right);  // Right-Left Case
        }
	std::cerr << "<<< Exiting insert(root=" << root << ",item=" << item << ")" << std::endl;
        return leftRotate(root);  // Right-Right Case
    }
    return root;
}

/**
 * @brief removes a given element from AVL tree
 * @param root of the tree
 * @param[in] element the element to be deleted from the tree
 * @return root of the updated tree
 */
node *deleteNode(node *root, int element) {
	std::cerr << ">>> Entering deleteNode(root=" << root << ",element=" << element << ")" << std::endl;
    if (root == nullptr) {
        return root;
    }
    if (element < root->data) {
        root->left = deleteNode(root->left, element);
    } else if (element > root->data) {
        root->right = deleteNode(root->right, element);

    } else {
        // Node to be deleted is leaf node or have only one Child
        if (!root->right || !root->left) {
            node *temp = !root->right ? root->left : root->right;
            delete root;
            return temp;
        }
        // Node to be deleted have both left and right subtrees
        node *temp = minValue(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    // Balancing Tree after deletion
	std::cerr << "<<< Exiting deleteNode(root=" << root << ",element=" << element << ")" << std::endl;
    return root;
}

/**
 * @brief calls delete on every node
 * @param root of the tree
 */
void deleteAllNodes(const node *const root) {
	std::cerr << ">>> Entering deleteAllNodes(root=" << root << ")" << std::endl;
    if (root) {
        deleteAllNodes(root->left);
        deleteAllNodes(root->right);
        delete root;
    }
	std::cerr << "<<< Exiting deleteAllNodes(root=" << root << ")" << std::endl;
}

/**
 * @brief prints given tree in the LevelOrder
 * @param[in] root of the tree
 */
void levelOrder(node *root) {
	std::cerr << ">>> Entering levelOrder(root=" << root << ")" << std::endl;
    std::queue<node *> q;
    q.push(root);
    while (!q.empty()) {
        root = q.front();
		std::cerr << "levelOrder(root=" << root << "): root → " << root << std::endl;
        std::cout << root->data << " ";
        q.pop();
        if (root->left) {
            q.push(root->left);
        }
        if (root->right) {
            q.push(root->right);
        }
    }
	std::cerr << "<<< Exiting levelOrder(root=" << root << ")" << std::endl;
}

/**
 * @brief Main function
 * @returns 0 on exit
 */
int main() {
	std::cerr << ">>> Entering main()" << std::endl;
    // Testing AVL Tree
    node *root = nullptr;
	std::cerr << "main(): root → " << root << std::endl;
    int i = 0;
    for (i = 1; i <= 7; i++) root = insert(root, i);
    std::cout << "LevelOrder: ";
    levelOrder(root);
    root = deleteNode(root, 1);  // Deleting key with value 1
    std::cout << "\nLevelOrder: ";
    levelOrder(root);
    root = deleteNode(root, 4);  // Deletin key with value 4
    std::cout << "\nLevelOrder: ";
    levelOrder(root);
    deleteAllNodes(root);
	std::cerr << "<<< Exiting main()" << std::endl;
    return 0;
}
