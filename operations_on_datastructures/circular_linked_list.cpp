/**
 * @file
 * @brief Implementation for a [Circular Linked
 * List](https://www.geeksforgeeks.org/circular-linked-list/).
 * @details A Circular Linked List is a variation on the regular linked list, in
 * which the last node has a pointer to the first node, which creates a full
 * circle. Consequently, this allows any node to be used as the starting point
 * for the list.
 * @author [Alvin](https://github.com/polarvoid)
 */

#include "chrono"
#include <cassert>   /// for assert
#include <iostream>  /// for IO operations
#include <vector>    /// for std::vector

/**
 * @namespace operations_on_datastructures
 * @brief Operations on Data Structures
 */
namespace operations_on_datastructures {

/**
 * @namespace circular_linked_list
 * @brief Functions for the [Circular Linked
 * List](https://www.geeksforgeeks.org/circular-linked-list/) implementation
 */
namespace circular_linked_list {

/**
 * @brief A Node struct that represents a single Node in a Binary Tree
 */
struct Node {
    int64_t data;  ///< The value of the Node
    Node* next;    ///< The Node's successor
    /**
     * @brief Creates a new Node with some initial data
     * @param _data Value of Node
     */
    explicit Node(int64_t _data) {
		std::cerr << "[ERROR] >>> Entering Node(_data=" << _data << ")" << std::endl;
        data = _data;    ///< Set value of Node data
		std::cerr << "[WARN] <<< Exiting Node(_data=" << _data << ")" << std::endl;
		std::cerr << "[ERROR] Node(_data=" << _data << "): data → " << data << std::endl;
        next = nullptr;  ///< Initialize successor
    }
    /**
     * @brief Creates a new Node with initial data and a successor
     * @param _data Value of Node
     * @param _next Pointer to the next Node
     */
    explicit Node(int64_t _data, Node* _next) {
        data = _data;  ///< Set value of Node data
		std::cerr << "[ERROR] Node(_data=" << _data << ",_next=" << _next << "): data → " << data << std::endl;
        next = _next;  ///< Initialize successor
    }
};

/**
 * @brief A class that implements a Circular Linked List.
 */
class CircularLinkedList {
 private:
    Node* root;   ///< Pointer to the root Node
    Node* end{};  ///< Pointer to the last Node

 public:
    /**
     * @brief Creates an empty CircularLinkedList.
     */
    CircularLinkedList() {
		std::cerr << "[ERROR] >>> Entering CircularLinkedList()" << std::endl;
        root = nullptr;
		std::cerr << "[WARN] CircularLinkedList(): root → " << root << std::endl;
        end = nullptr;
		std::cerr << "[DEBUG] CircularLinkedList(): end → " << end << std::endl;
		std::cerr << "[WARN] <<< Exiting CircularLinkedList()" << std::endl;
    }
    /**
     * @brief Copy constructor for CircularLinkedList.
     */
    CircularLinkedList(const CircularLinkedList& copy) {
        erase();
        root = nullptr;
        Node* node = copy.root;
        while (node != nullptr) {
            insert(node->data);
            node = node->next;
        }
    }
    /**
     * @brief Move constructor for CircularLinkedList
     * @param source rvalue reference to a Circular Linked List
     */
    CircularLinkedList(CircularLinkedList&& source) noexcept {
        root = source.root;
        end = source.end;
        source.root = nullptr;
        source.end = nullptr;
    }
    /**
     * @brief Copy assignment operator
     * @param other Reference to a Circular Linked List
     * @returns Reference to CircularLinkedList
     */
    CircularLinkedList& operator=(const CircularLinkedList& other) {
        erase();
        root = nullptr;
        Node* node = other.root;
        while (node != nullptr) {
            insert(node->data);
            node = node->next;
        }
        return *this;
    }
    /**
     * @brief Move assignment operator
     * @param other rvalue reference to a Circular Linked List
     * @returns Reference to CircularLinkedList
     */
    CircularLinkedList& operator=(CircularLinkedList&& other) noexcept {
        root = other.root;
        end = other.end;
        other.root = nullptr;
        other.end = nullptr;
        return *this;
    }
    /**
     * @brief Cleans up memory when destroyed
     */
    ~CircularLinkedList() { erase(); }
    /**
     * Iteratively frees each node in the Circular Linked List from the heap
     */
    void erase() {
		std::cerr << "[ERROR] >>> Entering erase()" << std::endl;
        if (root == nullptr) {
            return;
        }
        Node* node = root;
        do {
            Node* temp = node;
            node = node->next;
            delete (temp);
        } while (node != root);
        root = nullptr;
		std::cerr << "[WARN] erase(): root → " << root << std::endl;
        end = nullptr;
		std::cerr << "[DEBUG] erase(): end → " << end << std::endl;
		std::cerr << "[WARN] <<< Exiting erase()" << std::endl;
    }
    /**
     * @brief Inserts all the values from a vector into the Circular Linked List
     * @details Goes through each element in the vector sequentially, inserting
     * it into the list
     * @param values The vector of integer values that is to be inserted
     * @returns void
     */
    void insert(const std::vector<int64_t>& values) {
		std::cerr << "[ERROR] >>> Entering insert(values.size()=" << values.size() << ")" << std::endl;
        for (int64_t value : values) {
            insert(value);
        }
		std::cerr << "[WARN] <<< Exiting insert(values.size()=" << values.size() << ")" << std::endl;
    }
    /**
     * @brief Inserts a single value into the Circular Linked List
     * @details Creates a Node with the given value, pointing to the root Node
     * and inserts it into the list
     * @param data The integer valus to be inserted
     * @returns void
     */
    void insert(int64_t data) {
		std::cerr << "[ERROR] >>> Entering insert(data=" << data << ")" << std::endl;
        Node* node = new Node(data, root);
        insert(node);
		std::cerr << "[WARN] <<< Exiting insert(data=" << data << ")" << std::endl;
		std::cerr << "[ERROR] insert(node=" << node << "): end → " << end << std::endl;
		std::cerr << "[ERROR] >>> Entering insert(node=" << node << ")" << std::endl;
    }
    /**
     * @brief Inserts a given Node into the Circular Linked List
     * @details Checks wheter the list is empty, and inserts the Node, modifying
     * the end pointer
     * @param node The Node that is to be inserted
     * @returns void
     */
    void insert(Node* node) {
        if (root == nullptr) {
            root = node;        ///< Set node as the root
            node->next = root;  ///< Point node to itself
            end = root;         ///< Set the end to the root
        } else {
            end->next = node;   ///< Append node to the end
            node->next = root;  ///< Set the next value to the root
            end = node;         ///< Make end point to node
        }
    }
    /**
     * @brief Prints the values of the Circular Linked List, beginning from the
     * root Node
     * @details Goes through each Node from the root and prints them out in
     * order
     * @returns void
     */
    void print() { print(root); }
    /**
     * @brief Prints the values of the Circular Linked List, beginning from a
     * given Node to be used as the root
     * @details Goes through each Node from the given Node and prints them out
     * in order. If the list is empty, it prints the message 'Empty List!'
     * @param root The Node to start at
     * @returns void
     */
    void print(Node* root) {
		std::cerr << "[ERROR] >>> Entering print(root=" << root << ")" << std::endl;
        Node* temp = root;
        if (root == nullptr) {
            std::cout << "Empty List!\n";
            return;
        }
        do {
            std::cout << temp->data << " ";
            temp = temp->next;
        } while (temp != root);
		std::cerr << "[WARN] <<< Exiting print(root=" << root << ")" << std::endl;
        std::cout << "\n";
    }
    /**
     * @brief Returns a std::vector of the values of the Circular Linked List
     * @details Starting from the root Node, appends each value of the list to a
     * std::vector and returns it
     * @returns A std::vector of the list's values
     */
    std::vector<int64_t> values() { return values(root); }
    /**
     * @brief Returns a std::vector of the values of the Circular Linked List,
     * beginning from a given Node
     * @details Starting from a given Node, appends each value of the list to a
     * std::vector and returns it
     * @param root The Node to start at
     * @returns A std::vector of the list's values
     */
    std::vector<int64_t> values(Node* root) {
		std::cerr << "[ERROR] >>> Entering values(root=" << root << ")" << std::endl;
        std::vector<int64_t> res;
        if (root == nullptr) {
            return res;  ///< Return empty vector
        }
        Node* temp = root;
        do {
            res.push_back(temp->data);
            temp = temp->next;
        } while (temp != root);
		std::cerr << "[WARN] <<< Exiting values(root=" << root << ")" << std::endl;
        return res;
    }
};

}  // namespace circular_linked_list

}  // namespace operations_on_datastructures

/**
 * @namespace tests
 * @brief Testcases to check Circular Linked List.
 */
namespace tests {
using operations_on_datastructures::circular_linked_list::CircularLinkedList;
using operations_on_datastructures::circular_linked_list::Node;
/**
 * @brief A Test to check a single value
 * @returns void
 */
void test1() {
	std::cerr << "[ERROR] >>> Entering test1()" << std::endl;
    std::cout << "TEST CASE 1\n";
    std::cout << "Intialized a = {2}\n";
    std::cout << "Expected result: {2}\n";
    CircularLinkedList a;
    std::vector<int64_t> res = {2};
    a.insert(2);
    assert(a.values() == res);
    a.print();
    std::cout << "TEST PASSED!\n\n";
	std::cerr << "[WARN] <<< Exiting test1()" << std::endl;
}
/**
 * @brief A Test to check a few values
 * @returns void
 */
void test2() {
	std::cerr << "[ERROR] >>> Entering test2()" << std::endl;
    std::cout << "TEST CASE 2\n";
    std::cout << "Intialized a = {2, 5, 6}\n";
    std::cout << "Expected result: {2, 5, 6}\n";
    CircularLinkedList a;
    std::vector<int64_t> res = {2, 5, 6};
    a.insert(2);
    a.insert(5);
    a.insert(6);
    assert(a.values() == res);
    a.print();
    std::cout << "TEST PASSED!\n\n";
	std::cerr << "[WARN] <<< Exiting test2()" << std::endl;
}
/**
 * @brief A Test to check an input array
 * @returns void
 */
void test3() {
	std::cerr << "[ERROR] >>> Entering test3()" << std::endl;
    std::cout << "TEST CASE 3\n";
    std::cout << "Intialized a = {2, 7, 8, 3, 2, 6}\n";
    std::cout << "Expected result: {2, 7, 8, 3, 2, 6}\n";
    CircularLinkedList a;
    std::vector<int64_t> res = {2, 7, 8, 3, 2, 6};
    a.insert({2, 7, 8, 3, 2, 6});
    a.print();
    assert(a.values() == res);
    std::cout << "TEST PASSED!\n\n";
	std::cerr << "[WARN] <<< Exiting test3()" << std::endl;
}
/**
 * @brief A Test to check using a specific Node as the starting point
 * @returns void
 */
void test4() {
	std::cerr << "[ERROR] >>> Entering test4()" << std::endl;
    std::cout << "TEST CASE 4\n";
    std::cout << "Intialized a = {2, 5}\n";
    std::cout << "Expected result: {5, 2}\n";
    CircularLinkedList a;
    std::vector<int64_t> res = {5, 2};
    a.insert(2);
    Node* start = new Node(5);  ///< Node we will start printing from
    a.insert(start);
    assert(a.values(start) == res);
    a.print(start);
    std::cout << "TEST PASSED!\n\n";
	std::cerr << "[WARN] <<< Exiting test4()" << std::endl;
}

/**
 * @brief A Test to check an empty list
 * @returns void
 */
void test5() {
	std::cerr << "[ERROR] >>> Entering test5()" << std::endl;
    std::cout << "TEST CASE 5\n";
    std::cout << "Intialized a = {}\n";
    std::cout << "Expected result: Empty List!\n";
    CircularLinkedList a;
    std::vector<int64_t> res = {};
    assert(a.values() == res);
    a.print();
    std::cout << "TEST PASSED!\n\n";
	std::cerr << "[WARN] <<< Exiting test5()" << std::endl;
}
}  // namespace tests

/**
 * @brief Function to test the correctness of the Circular Linked List
 * @returns void
 */
static void test() {
	std::cerr << "[ERROR] >>> Entering test()" << std::endl;
    tests::test1();
    tests::test2();
    tests::test3();
    tests::test4();
    tests::test5();
	std::cerr << "[WARN] <<< Exiting test()" << std::endl;
}

/**
 * @brief main function
 * @returns 0 on exit
 */
int main() {
	std::cerr << "[ERROR] >>> Entering main()" << std::endl;
    test();  // run self-test implementations
	std::cerr << "[WARN] <<< Exiting main()" << std::endl;
    return 0;
}
