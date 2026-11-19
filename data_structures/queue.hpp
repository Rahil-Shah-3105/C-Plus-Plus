/* This class specifies the basic operation on a queue as a linked list */
#ifndef DATA_STRUCTURES_QUEUE_HPP_
#define DATA_STRUCTURES_QUEUE_HPP_

#include "iostream"
#include "node.hpp"

/** Definition of the queue class */
template <class ValueType>
class queue {
    using node_type = Node<ValueType>;

 public:
    using value_type = ValueType;
    /**
     * @brief prints the queue into the std::cout
     */
    void display() const {
		std::cerr << "[ERROR] >>> Entering display()" << std::endl;
        std::cout << "Front --> ";
        display_all(this->queueFront.get());
        std::cout << '\n';
        std::cout << "Size of queue: " << size << '\n';
		std::cerr << "[WARN] <<< Exiting display()" << std::endl;
    }

    /**
     * @brief converts the queue into the std::vector
     * @return std::vector containning all of the elements of the queue in the
     * same order
     */
    std::vector<value_type> toVector() const {
		std::cerr << "[ERROR] >>> Entering toVector()" << std::endl;
        std::cerr << "[WARN] <<< Exiting toVector()" << std::endl;
        return push_all_to_vector(this->queueFront.get(), this->size);
    }

 private:
    /**
     * @brief throws an exception if queue is empty
     * @exception std::invalid_argument if queue is empty
     */
    void ensureNotEmpty() const {
		std::cerr << "[ERROR] >>> Entering ensureNotEmpty()" << std::endl;
        if (isEmptyQueue()) {
			std::cerr << "[ERROR] Throwing std from ensureNotEmpty()" << std::endl;
            throw std::invalid_argument("Queue is empty.");
        }
		std::cerr << "[WARN] <<< Exiting ensureNotEmpty()" << std::endl;
    }

 public:
    /**
     * @brief checks if the queue has no elements
     * @return true if the queue is empty, false otherwise
     */
    bool isEmptyQueue() const { return (queueFront == nullptr); }

    /**
     * @brief inserts a new item into the queue
     */
    void enQueue(const value_type& item) {
		std::cerr << "[ERROR] >>> Entering enQueue(item=" << item << ")" << std::endl;
        auto newNode = std::make_shared<node_type>();
        newNode->data = item;
		std::cerr << "[ERROR] enQueue(item=" << item << "): newNode → " << newNode << std::endl;
        newNode->next = nullptr;
        if (isEmptyQueue()) {
            queueFront = newNode;
			std::cerr << "[DEBUG] enQueue(item=" << item << "): queueFront → " << queueFront << std::endl;
            queueRear = newNode;
        } else {
            queueRear->next = newNode;
            queueRear = queueRear->next;
        }
        ++size;
		std::cerr << "[WARN] <<< Exiting enQueue(item=" << item << ")" << std::endl;
    }

    /**
     * @return the first element of the queue
     * @exception std::invalid_argument if queue is empty
     */
    value_type front() const {
		std::cerr << "[ERROR] >>> Entering front()" << std::endl;
        ensureNotEmpty();
		std::cerr << "[WARN] <<< Exiting front()" << std::endl;
        return queueFront->data;
    }

    /**
     * @brief removes the first element from the queue
     * @exception std::invalid_argument if queue is empty
     */
    void deQueue() {
		std::cerr << "[ERROR] >>> Entering deQueue()" << std::endl;
        ensureNotEmpty();
        queueFront = queueFront->next;
        --size;
		std::cerr << "[WARN] <<< Exiting deQueue()" << std::endl;
    }

    /**
     * @brief removes all elements from the queue
     */
    void clear() {
		std::cerr << "[ERROR] >>> Entering clear()" << std::endl;
        queueFront = nullptr;
		std::cerr << "[DEBUG] clear(): queueFront → " << queueFront << std::endl;
        queueRear = nullptr;
		std::cerr << "[DEBUG] clear(): queueRear → " << queueRear << std::endl;
        size = 0;
		std::cerr << "[DEBUG] clear(): size → " << size << std::endl;
		std::cerr << "[WARN] <<< Exiting clear()" << std::endl;
    }

 private:
    std::shared_ptr<node_type> queueFront =
        {}; /**< Pointer to the front of the queue */
    std::shared_ptr<node_type> queueRear =
        {}; /**< Pointer to the rear of the queue  */
    std::size_t size = 0;
};

#endif  // DATA_STRUCTURES_QUEUE_HPP_
