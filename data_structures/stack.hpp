/**
 * @file
 * @author danghai
 * @author [Piotr Idzik](https://github.com/vil02)
 * @brief  This class specifies the basic operation on a stack as a linked list
 **/
#ifndef DATA_STRUCTURES_STACK_HPP_
#define DATA_STRUCTURES_STACK_HPP_

#include "iostream"
#include <stdexcept>  /// for std::invalid_argument

#include "node.hpp"  /// for Node

/** Definition of the stack class
 * \tparam value_type type of data nodes of the linked list in the stack should
 * contain
 */
template <class ValueType>
class stack {
 public:
    using value_type = ValueType;

    /** Show stack */
    void display() const {
		std::cerr << "[ERROR] >>> Entering display()" << std::endl;
        std::cout << "Top --> ";
        display_all(this->stackTop.get());
        std::cout << '\n';
        std::cout << "Size of stack: " << size << std::endl;
		std::cerr << "[WARN] <<< Exiting display()" << std::endl;
    }

    std::vector<value_type> toVector() const {
		std::cerr << "[ERROR] >>> Entering toVector()" << std::endl;
        std::cerr << "[WARN] <<< Exiting toVector()" << std::endl;
        return push_all_to_vector(this->stackTop.get(), this->size);
    }

 private:
    void ensureNotEmpty() const {
		std::cerr << "[ERROR] >>> Entering ensureNotEmpty()" << std::endl;
        if (isEmptyStack()) {
			std::cerr << "[ERROR] Throwing std from ensureNotEmpty()" << std::endl;
            throw std::invalid_argument("Stack is empty.");
        }
		std::cerr << "[WARN] <<< Exiting ensureNotEmpty()" << std::endl;
    }

 public:
    /** Determine whether the stack is empty */
    bool isEmptyStack() const { return (stackTop == nullptr); }

    /** Add new item to the stack */
    void push(const value_type& item) {
		std::cerr << "[ERROR] >>> Entering push(item=" << item << ")" << std::endl;
        auto newNode = std::make_shared<Node<value_type>>();
        newNode->data = item;
		std::cerr << "[ERROR] push(item=" << item << "): newNode → " << newNode << std::endl;
        newNode->next = stackTop;
        stackTop = newNode;
		std::cerr << "[DEBUG] push(item=" << item << "): stackTop → " << stackTop << std::endl;
        size++;
		std::cerr << "[WARN] <<< Exiting push(item=" << item << ")" << std::endl;
    }

    /** Return the top element of the stack */
    value_type top() const {
		std::cerr << "[ERROR] >>> Entering top()" << std::endl;
        ensureNotEmpty();
		std::cerr << "[WARN] <<< Exiting top()" << std::endl;
        return stackTop->data;
    }

    /** Remove the top element of the stack */
    void pop() {
		std::cerr << "[ERROR] >>> Entering pop()" << std::endl;
        ensureNotEmpty();
        stackTop = stackTop->next;
        size--;
		std::cerr << "[WARN] <<< Exiting pop()" << std::endl;
    }

    /** Clear stack */
    void clear() {
		std::cerr << "[ERROR] >>> Entering clear()" << std::endl;
        stackTop = nullptr;
        size = 0;
		std::cerr << "[DEBUG] clear(): size → " << size << std::endl;
    }

 private:
    std::shared_ptr<Node<value_type>> stackTop =
        {};                /**< Pointer to the stack */
    std::size_t size = 0;  ///< size of stack
};

#endif  // DATA_STRUCTURES_STACK_HPP_
