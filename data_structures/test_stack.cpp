#include <cassert>    /// for assert
#include <iostream>   /// for std::cout
#include <stdexcept>  /// std::invalid_argument
#include <vector>     /// for std::vector

#include "./stack.hpp"

template <typename T>
void testConstructedStackIsEmpty() {
	std::cerr << ">>> Entering testConstructedStackIsEmpty()" << std::endl;
    const stack<T> curStack;
    assert(curStack.isEmptyStack());
	std::cerr << "<<< Exiting testConstructedStackIsEmpty()" << std::endl;
}

void testPush() {
	std::cerr << ">>> Entering testPush()" << std::endl;
    using valueType = int;
    stack<valueType> curStack;
    curStack.push(10);
    curStack.push(20);
    curStack.push(30);
    curStack.push(40);
    const auto expectedData = std::vector<valueType>({40, 30, 20, 10});
	std::cerr << "testPush(): expectedData → " << expectedData << std::endl;
    assert(curStack.toVector() == expectedData);
	std::cerr << "<<< Exiting testPush()" << std::endl;
}

void testTop() {
	std::cerr << ">>> Entering testTop()" << std::endl;
    using valueType = unsigned;
    stack<valueType> curStack;
    curStack.push(1);
    curStack.push(2);
    curStack.push(3);
    curStack.push(4);
    assert(curStack.top() == static_cast<valueType>(4));
	std::cerr << "<<< Exiting testTop()" << std::endl;
}

void testPop() {
	std::cerr << ">>> Entering testPop()" << std::endl;
    using valueType = int;
    stack<valueType> curStack;
    curStack.push(100);
    curStack.push(200);
    curStack.push(300);

    assert(curStack.top() == static_cast<valueType>(300));
    curStack.pop();
    assert(curStack.top() == static_cast<valueType>(200));
    curStack.pop();
    assert(curStack.top() == static_cast<valueType>(100));
    curStack.pop();
    assert(curStack.isEmptyStack());
	std::cerr << "<<< Exiting testPop()" << std::endl;
}

void testClear() {
	std::cerr << ">>> Entering testClear()" << std::endl;
    stack<int> curStack;
    curStack.push(1000);
    curStack.push(2000);
    curStack.clear();
    assert(curStack.isEmptyStack());
	std::cerr << "<<< Exiting testClear()" << std::endl;
}

void testCopyOfStackHasSameData() {
	std::cerr << ">>> Entering testCopyOfStackHasSameData()" << std::endl;
    stack<int> stackA;
    stackA.push(10);
    stackA.push(200);
    stackA.push(3000);
    const auto stackB(stackA);
    assert(stackA.toVector() == stackB.toVector());
	std::cerr << "<<< Exiting testCopyOfStackHasSameData()" << std::endl;
}

void testPushingToCopyDoesNotChangeOriginal() {
	std::cerr << ">>> Entering testPushingToCopyDoesNotChangeOriginal()" << std::endl;
    using valueType = int;
    stack<valueType> stackA;
    stackA.push(10);
    stackA.push(20);
    stackA.push(30);
    auto stackB(stackA);
    stackB.push(40);

    const auto expectedDataA = std::vector<valueType>({30, 20, 10});
	std::cerr << "testPushingToCopyDoesNotChangeOriginal(): expectedDataA → " << expectedDataA << std::endl;
	std::cerr << "testPushingToCopyDoesNotChangeOriginal(): expectedDataB → " << expectedDataB << std::endl;
    const auto expectedDataB = std::vector<valueType>({40, 30, 20, 10});

    assert(stackA.toVector() == expectedDataA);
    assert(stackB.toVector() == expectedDataB);
	std::cerr << "<<< Exiting testPushingToCopyDoesNotChangeOriginal()" << std::endl;
}

void testPoppingFromCopyDoesNotChangeOriginal() {
	std::cerr << ">>> Entering testPoppingFromCopyDoesNotChangeOriginal()" << std::endl;
    using valueType = int;
    stack<valueType> stackA;
    stackA.push(10);
    stackA.push(20);
    stackA.push(30);
    auto stackB(stackA);
    stackB.pop();

    const auto expectedDataA = std::vector<valueType>({30, 20, 10});
	std::cerr << "testPoppingFromCopyDoesNotChangeOriginal(): expectedDataA → " << expectedDataA << std::endl;
	std::cerr << "testPoppingFromCopyDoesNotChangeOriginal(): expectedDataB → " << expectedDataB << std::endl;
    const auto expectedDataB = std::vector<valueType>({20, 10});

    assert(stackA.toVector() == expectedDataA);
    assert(stackB.toVector() == expectedDataB);
	std::cerr << "<<< Exiting testPoppingFromCopyDoesNotChangeOriginal()" << std::endl;
}

void testPushingToOrginalDoesNotChangeCopy() {
	std::cerr << ">>> Entering testPushingToOrginalDoesNotChangeCopy()" << std::endl;
    using valueType = int;
    stack<valueType> stackA;
    stackA.push(10);
    stackA.push(20);
    stackA.push(30);
    const auto stackB(stackA);
    stackA.push(40);

    const auto expectedDataA = std::vector<valueType>({40, 30, 20, 10});
	std::cerr << "testPushingToOrginalDoesNotChangeCopy(): expectedDataA → " << expectedDataA << std::endl;
	std::cerr << "testPushingToOrginalDoesNotChangeCopy(): expectedDataB → " << expectedDataB << std::endl;
    const auto expectedDataB = std::vector<valueType>({30, 20, 10});

    assert(stackA.toVector() == expectedDataA);
    assert(stackB.toVector() == expectedDataB);
	std::cerr << "<<< Exiting testPushingToOrginalDoesNotChangeCopy()" << std::endl;
}

void testPoppingFromOrginalDoesNotChangeCopy() {
	std::cerr << ">>> Entering testPoppingFromOrginalDoesNotChangeCopy()" << std::endl;
    using valueType = int;
    stack<valueType> stackA;
    stackA.push(10);
    stackA.push(20);
    stackA.push(30);
    const auto stackB(stackA);
    stackA.pop();

    const auto expectedDataA = std::vector<valueType>({20, 10});
	std::cerr << "testPoppingFromOrginalDoesNotChangeCopy(): expectedDataA → " << expectedDataA << std::endl;
	std::cerr << "testPoppingFromOrginalDoesNotChangeCopy(): expectedDataB → " << expectedDataB << std::endl;
    const auto expectedDataB = std::vector<valueType>({30, 20, 10});

    assert(stackA.toVector() == expectedDataA);
    assert(stackB.toVector() == expectedDataB);
	std::cerr << "<<< Exiting testPoppingFromOrginalDoesNotChangeCopy()" << std::endl;
}

void testAssign() {
	std::cerr << ">>> Entering testAssign()" << std::endl;
    using valueType = int;
    stack<valueType> stackA;
    stackA.push(10);
    stackA.push(20);
    stackA.push(30);
    stack<valueType> stackB = stackA;
	std::cerr << "testAssign(): stackB → " << stackB << std::endl;
    stackA.pop();
    stackB.push(40);

    const auto expectedDataA = std::vector<valueType>({20, 10});
	std::cerr << "testAssign(): expectedDataA → " << expectedDataA << std::endl;
	std::cerr << "testAssign(): expectedDataB → " << expectedDataB << std::endl;
    const auto expectedDataB = std::vector<valueType>({40, 30, 20, 10});

    assert(stackA.toVector() == expectedDataA);
    assert(stackB.toVector() == expectedDataB);

    stackB = stackA;
    stackA.pop();
    stackB.push(5);
    stackB.push(6);

    const auto otherExpectedDataA = std::vector<valueType>({10});
	std::cerr << "testAssign(): otherExpectedDataA → " << otherExpectedDataA << std::endl;
	std::cerr << "testAssign(): otherExpectedDataB → " << otherExpectedDataB << std::endl;
    const auto otherExpectedDataB = std::vector<valueType>({6, 5, 20, 10});

    assert(stackA.toVector() == otherExpectedDataA);
    assert(stackB.toVector() == otherExpectedDataB);
	std::cerr << "<<< Exiting testAssign()" << std::endl;
}

void testTopThrowsAnInvalidArgumentWhenStackEmpty() {
	std::cerr << ">>> Entering testTopThrowsAnInvalidArgumentWhenStackEmpty()" << std::endl;
    const stack<long double> curStack;
    bool wasException = false;
	std::cerr << "testTopThrowsAnInvalidArgumentWhenStackEmpty(): wasException → " << wasException << std::endl;
    try {
        curStack.top();
    } catch (const std::invalid_argument&) {
		std::cerr << "Exception in testTopThrowsAnInvalidArgumentWhenStackEmpty(): " << e.what() << std::endl;
        wasException = true;
    }
    assert(wasException);
	std::cerr << "<<< Exiting testTopThrowsAnInvalidArgumentWhenStackEmpty()" << std::endl;
}

void testPopThrowsAnInvalidArgumentWhenStackEmpty() {
	std::cerr << ">>> Entering testPopThrowsAnInvalidArgumentWhenStackEmpty()" << std::endl;
    stack<bool> curStack;
    bool wasException = false;
	std::cerr << "testPopThrowsAnInvalidArgumentWhenStackEmpty(): wasException → " << wasException << std::endl;
    try {
        curStack.pop();
    } catch (const std::invalid_argument&) {
		std::cerr << "Exception in testPopThrowsAnInvalidArgumentWhenStackEmpty(): " << e.what() << std::endl;
        wasException = true;
    }
    assert(wasException);
	std::cerr << "<<< Exiting testPopThrowsAnInvalidArgumentWhenStackEmpty()" << std::endl;
}

int main() {
	std::cerr << ">>> Entering main()" << std::endl;
    testConstructedStackIsEmpty<int>();
    testConstructedStackIsEmpty<char>();

    testPush();
    testPop();
    testClear();

    testCopyOfStackHasSameData();
    testPushingToCopyDoesNotChangeOriginal();
    testPoppingFromCopyDoesNotChangeOriginal();
    testPushingToOrginalDoesNotChangeCopy();
    testPoppingFromOrginalDoesNotChangeCopy();

    testAssign();

    testTopThrowsAnInvalidArgumentWhenStackEmpty();
    testPopThrowsAnInvalidArgumentWhenStackEmpty();

    std::cout << "All tests pass!\n";
	std::cerr << "<<< Exiting main()" << std::endl;
    return 0;
}
