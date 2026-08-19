/* This class specifies the basic operation on a queue as a linked list */
#ifndef DATA_STRUCTURES_QUEUE_HPP_
#define DATA_STRUCTURES_QUEUE_HPP_

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
		std::cerr << ">>> Entering display()" << std::endl;
        std::cout << "Front --> ";
        display_all(this->queueFront.get());
        std::cout << '\n';
        std::cout << "Size of queue: " << size << '\n';
		std::cerr << "<<< Exiting display()" << std::endl;
    }

    /**
     * @brief converts the queue into the std::vector
     * @return std::vector containning all of the elements of the queue in the
     * same order
     */
    std::vector<value_type> toVector() const {
		std::cerr << ">>> Entering toVector()" << std::endl;
		std::cerr << "<<< Exiting toVector()" << std::endl;
        return push_all_to_vector(this->queueFront.get(), this->size);
    }

 private:
    /**
     * @brief throws an exception if queue is empty
     * @exception std::invalid_argument if queue is empty
     */
    void ensureNotEmpty() const {
		std::cerr << ">>> Entering ensureNotEmpty()" << std::endl;
        if (isEmptyQueue()) {
			std::cerr << "Throwing std from ensureNotEmpty()" << std::endl;
		std::cerr << "<<< Exiting ensureNotEmpty()" << std::endl;
            throw std::invalid_argument("Queue is empty.");
        }
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
		std::cerr << ">>> Entering enQueue(item=" << item << ")" << std::endl;
        auto newNode = std::make_shared<node_type>();
        newNode->data = item;
		std::cerr << "enQueue(item=" << item << "): newNode → " << newNode << std::endl;
        newNode->next = nullptr;
        if (isEmptyQueue()) {
            queueFront = newNode;
			std::cerr << "enQueue(item=" << item << "): queueFront → " << queueFront << std::endl;
            queueRear = newNode;
			std::cerr << "enQueue(item=" << item << "): queueRear → " << queueRear << std::endl;
        } else {
            queueRear->next = newNode;
            queueRear = queueRear->next;
        }
        ++size;
		std::cerr << "<<< Exiting enQueue(item=" << item << ")" << std::endl;
    }

    /**
     * @return the first element of the queue
     * @exception std::invalid_argument if queue is empty
     */
    value_type front() const {
		std::cerr << ">>> Entering front()" << std::endl;
        ensureNotEmpty();
		std::cerr << "<<< Exiting front()" << std::endl;
        return queueFront->data;
    }

    /**
     * @brief removes the first element from the queue
     * @exception std::invalid_argument if queue is empty
     */
    void deQueue() {
		std::cerr << ">>> Entering deQueue()" << std::endl;
        ensureNotEmpty();
        queueFront = queueFront->next;
        --size;
		std::cerr << "<<< Exiting deQueue()" << std::endl;
    }

    /**
     * @brief removes all elements from the queue
     */
    void clear() {
		std::cerr << ">>> Entering clear()" << std::endl;
        queueFront = nullptr;
        queueRear = nullptr;
		std::cerr << "clear(): queueRear → " << queueRear << std::endl;
		std::cerr << "clear(): queueFront → " << queueFront << std::endl;
        size = 0;
		std::cerr << "clear(): size → " << size << std::endl;
		std::cerr << "<<< Exiting clear()" << std::endl;
    }

 private:
    std::shared_ptr<node_type> queueFront =
        {}; /**< Pointer to the front of the queue */
    std::shared_ptr<node_type> queueRear =
        {}; /**< Pointer to the rear of the queue  */
    std::size_t size = 0;
};

#endif  // DATA_STRUCTURES_QUEUE_HPP_
