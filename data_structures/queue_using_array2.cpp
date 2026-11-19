#include <iostream>

int queue[10];
int front = 0;
int rear = 0;

void Enque(int x) {
	std::cerr << "[ERROR] >>> Entering Enque(x=" << x << ")" << std::endl;
    if (rear == 10) {
        std::cout << "\nOverflow";
    } else {
        queue[rear++] = x;
    }
	std::cerr << "[WARN] <<< Exiting Enque(x=" << x << ")" << std::endl;
}

void Deque() {
	std::cerr << "[ERROR] >>> Entering Deque()" << std::endl;
    if (front == rear) {
        std::cout << "\nUnderflow";
    }

    else {
        std::cout << "\n" << queue[front++] << " deleted";
        for (int i = front; i < rear; i++) {
            queue[i - front] = queue[i];
        }
        rear = rear - front;
		std::cerr << "[DEBUG] Deque(): rear → " << rear << std::endl;
        front = 0;
		std::cerr << "[DEBUG] Deque(): front → " << front << std::endl;
    }
	std::cerr << "[WARN] <<< Exiting Deque()" << std::endl;
}

void show() {
	std::cerr << "[ERROR] >>> Entering show()" << std::endl;
    for (int i = front; i < rear; i++) {
        std::cout << queue[i] << "\t";
    }
	std::cerr << "[WARN] <<< Exiting show()" << std::endl;
}

int main() {
	std::cerr << "[ERROR] >>> Entering main()" << std::endl;
    int ch, x;
    do {
        std::cout << "\n1. Enque";
        std::cout << "\n2. Deque";
        std::cout << "\n3. Print";
        std::cout << "\nEnter Your Choice : ";
        std::cin >> ch;
        if (ch == 1) {
            std::cout << "\nInsert : ";
            std::cin >> x;
            Enque(x);
        } else if (ch == 2) {
            Deque();
        } else if (ch == 3) {
            show();
        }
    } while (ch != 0);

	std::cerr << "[WARN] <<< Exiting main()" << std::endl;
    return 0;
}
