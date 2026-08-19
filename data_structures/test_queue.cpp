#include <cassert>   /// for assert
#include <iostream>  /// for std::cout

#include "./queue.hpp"

template <typename T>
void testConstructedQueueIsEmpty() {
	std::cerr << ">>> Entering testConstructedQueueIsEmpty()" << std::endl;
    const queue<T> curQueue;
    assert(curQueue.isEmptyQueue());
	std::cerr << "<<< Exiting testConstructedQueueIsEmpty()" << std::endl;
}

void testEnQueue() {
	std::cerr << ">>> Entering testEnQueue()" << std::endl;
    queue<int> curQueue;
    curQueue.enQueue(10);
    assert(curQueue.toVector() == std::vector<int>({10}));
    curQueue.enQueue(20);
    assert(curQueue.toVector() == std::vector<int>({10, 20}));
    curQueue.enQueue(30);
    curQueue.enQueue(40);
    assert(curQueue.toVector() == std::vector<int>({10, 20, 30, 40}));
	std::cerr << "<<< Exiting testEnQueue()" << std::endl;
}

void testDeQueue() {
	std::cerr << ">>> Entering testDeQueue()" << std::endl;
    queue<int> curQueue;
    curQueue.enQueue(10);
    curQueue.enQueue(20);
    curQueue.enQueue(30);

    curQueue.deQueue();
    assert(curQueue.toVector() == std::vector<int>({20, 30}));

    curQueue.deQueue();
    assert(curQueue.toVector() == std::vector<int>({30}));

    curQueue.deQueue();
    assert(curQueue.isEmptyQueue());
	std::cerr << "<<< Exiting testDeQueue()" << std::endl;
}

void testFront() {
	std::cerr << ">>> Entering testFront()" << std::endl;
    queue<int> curQueue;
    curQueue.enQueue(10);
    assert(curQueue.front() == 10);
    curQueue.enQueue(20);
    assert(curQueue.front() == 10);
	std::cerr << "<<< Exiting testFront()" << std::endl;
}

void testQueueAfterClearIsEmpty() {
	std::cerr << ">>> Entering testQueueAfterClearIsEmpty()" << std::endl;
    queue<int> curQueue;
    curQueue.enQueue(10);
    curQueue.enQueue(20);
    curQueue.enQueue(30);
    curQueue.clear();
    assert(curQueue.isEmptyQueue());
	std::cerr << "<<< Exiting testQueueAfterClearIsEmpty()" << std::endl;
}

void testFrontThrowsAnInvalidArgumentWhenQueueEmpty() {
	std::cerr << ">>> Entering testFrontThrowsAnInvalidArgumentWhenQueueEmpty()" << std::endl;
    const queue<int> curQueue;
    bool wasException = false;
	std::cerr << "testFrontThrowsAnInvalidArgumentWhenQueueEmpty(): wasException → " << wasException << std::endl;
    try {
        curQueue.front();
    } catch (const std::invalid_argument&) {
		std::cerr << "Exception in testFrontThrowsAnInvalidArgumentWhenQueueEmpty(): " << e.what() << std::endl;
        wasException = true;
    }
    assert(wasException);
	std::cerr << "<<< Exiting testFrontThrowsAnInvalidArgumentWhenQueueEmpty()" << std::endl;
}

void testDeQueueThrowsAnInvalidArgumentWhenQueueEmpty() {
	std::cerr << ">>> Entering testDeQueueThrowsAnInvalidArgumentWhenQueueEmpty()" << std::endl;
    queue<int> curQueue;
    bool wasException = false;
	std::cerr << "testDeQueueThrowsAnInvalidArgumentWhenQueueEmpty(): wasException → " << wasException << std::endl;
    try {
        curQueue.deQueue();
    } catch (const std::invalid_argument&) {
		std::cerr << "Exception in testDeQueueThrowsAnInvalidArgumentWhenQueueEmpty(): " << e.what() << std::endl;
        wasException = true;
    }
    assert(wasException);
	std::cerr << "<<< Exiting testDeQueueThrowsAnInvalidArgumentWhenQueueEmpty()" << std::endl;
}

int main() {
	std::cerr << ">>> Entering main()" << std::endl;
    testConstructedQueueIsEmpty<int>();
    testConstructedQueueIsEmpty<double>();
    testConstructedQueueIsEmpty<std::vector<long double>>();

    testEnQueue();
    testDeQueue();

    testQueueAfterClearIsEmpty();

    testFrontThrowsAnInvalidArgumentWhenQueueEmpty();
    testDeQueueThrowsAnInvalidArgumentWhenQueueEmpty();

    std::cout << "All tests pass!\n";
	std::cerr << "<<< Exiting main()" << std::endl;
    return 0;
}
