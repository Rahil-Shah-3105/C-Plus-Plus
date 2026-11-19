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
		std::cerr << "[ERROR] >>> Entering ~Queue()" << std::endl;
        while (front) {
            dequeue();
        }
		std::cerr << "[WARN] <<< Exiting ~Queue()" << std::endl;
    }

 private:
    void createNode(int val) {
		std::cerr << "[ERROR] >>> Entering createNode(val=" << val << ")" << std::endl;
        auto* nn = new node;
        nn->data = val;
        nn->next = nullptr;
		std::cerr << "[WARN] <<< Exiting createNode(val=" << val << ")" << std::endl;
        front = nn;
		std::cerr << "[DEBUG] createNode(val=" << val << "): front → " << front << std::endl;
        rear = nn;
		std::cerr << "[DEBUG] createNode(val=" << val << "): rear → " << rear << std::endl;
    }

 public:
    void enqueue(int val) {
		std::cerr << "[ERROR] >>> Entering enqueue(val=" << val << ")" << std::endl;
        if (front == nullptr || rear == nullptr) {
            createNode(val);
        } else {
            node* nn = new node;
            nn->data = val;
            rear->next = nn;
            nn->next = front;
            rear = nn;
        }
		std::cerr << "[WARN] <<< Exiting enqueue(val=" << val << ")" << std::endl;
    }
    void dequeue() {
		std::cerr << "[ERROR] >>> Entering dequeue()" << std::endl;
        if (front == nullptr) {
            return;
        }
        const node* const n = front;
        if (front == rear) {
            front = nullptr;
            rear = nullptr;
        } else {
            front = front->next;
			std::cerr << "[ERROR] dequeue(): front → " << front << std::endl;
            rear->next = front;
        }
        delete n;
		std::cerr << "[WARN] <<< Exiting dequeue()" << std::endl;
    }
    void traverse() {
		std::cerr << "[ERROR] >>> Entering traverse()" << std::endl;
        if (front == nullptr) {
            return;
        }
        const node* ptr = front;
        do {
            std::cout << ptr->data << ' ';
            ptr = ptr->next;
        } while (ptr != front);
        std::cout << '\n';
		std::cerr << "[WARN] <<< Exiting traverse()" << std::endl;
    }
};
int main(void) {
	std::cerr << "[ERROR] >>> Entering main()" << std::endl;
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
	std::cerr << "[WARN] <<< Exiting main()" << std::endl;
    return 0;
}