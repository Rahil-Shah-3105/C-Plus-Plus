#include <iostream>

struct node {
    int data;
    struct node* next;
};
class Queue {
    node* front = nullptr;
    node* rear = nullptr;

    Queue(const Queue&) = delete;
    Queue& operator=(const Queue&) = delete;

 public:
    Queue() = default;
    ~Queue() {
		std::cerr << ">>> Entering ~Queue()" << std::endl;
        while (front) {
            dequeue();
        }
		std::cerr << "<<< Exiting ~Queue()" << std::endl;
    }

 private:
    void createNode(int val) {
		std::cerr << ">>> Entering createNode(val=" << val << ")" << std::endl;
        auto* nn = new node;
        nn->data = val;
        nn->next = nullptr;
		std::cerr << "<<< Exiting createNode(val=" << val << ")" << std::endl;
		std::cerr << "createNode(val=" << val << "): front → " << front << std::endl;
		std::cerr << "createNode(val=" << val << "): rear → " << rear << std::endl;
        front = nn;
        rear = nn;
    }

 public:
    void enqueue(int val) {
		std::cerr << ">>> Entering enqueue(val=" << val << ")" << std::endl;
        if (front == nullptr || rear == nullptr) {
            createNode(val);
        } else {
            node* nn = new node;
            nn->data = val;
            rear->next = nn;
            nn->next = front;
            rear = nn;
        }
		std::cerr << "<<< Exiting enqueue(val=" << val << ")" << std::endl;
    }
    void dequeue() {
		std::cerr << ">>> Entering dequeue()" << std::endl;
        if (front == nullptr) {
            return;
        }
        const node* const n = front;
        if (front == rear) {
            front = nullptr;
			std::cerr << "dequeue(): front → " << front << std::endl;
            rear = nullptr;
        } else {
            front = front->next;
            rear->next = front;
        }
        delete n;
		std::cerr << "<<< Exiting dequeue()" << std::endl;
    }
    void traverse() {
		std::cerr << ">>> Entering traverse()" << std::endl;
        if (front == nullptr) {
            return;
        }
        const node* ptr = front;
        do {
            std::cout << ptr->data << ' ';
            ptr = ptr->next;
        } while (ptr != front);
        std::cout << '\n';
		std::cerr << "<<< Exiting traverse()" << std::endl;
    }
};
int main(void) {
	std::cerr << ">>> Entering main()" << std::endl;
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);
    q.enqueue(70);
    q.traverse();
    q.dequeue();
    q.traverse();
	std::cerr << "<<< Exiting main()" << std::endl;
    return 0;
}