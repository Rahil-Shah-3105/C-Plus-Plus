#include <iostream>
using std::cin;
using std::cout;

int queue[10];
int front = 0;
int rear = 0;
int count = 0;

void Enque(int x) {
	std::cerr << "[ERROR] >>> Entering Enque(x=" << x << ")" << std::endl;
    if (count == 10) {
        cout << "\nOverflow";
    } else {
        queue[rear] = x;
        rear = (rear + 1) % 10;
		std::cerr << "[ERROR] Enque(x=" << x << "): rear → " << rear << std::endl;
		std::cerr << "[DEBUG] Enque(x=" << x << "): rear → " << rear << std::endl;
        count++;
    }
	std::cerr << "[WARN] <<< Exiting Enque(x=" << x << ")" << std::endl;
}

void Deque() {
	std::cerr << "[ERROR] >>> Entering Deque()" << std::endl;
    if (front == rear) {
        cout << "\nUnderflow";
    }

    else {
        cout << "\n" << queue[front] << " deleted";
        front = (front + 1) % 10;
		std::cerr << "[ERROR] Deque(): front → " << front << std::endl;
		std::cerr << "[DEBUG] Deque(): front → " << front << std::endl;
        count--;
    }
	std::cerr << "[WARN] <<< Exiting Deque()" << std::endl;
}

void show() {
	std::cerr << "[ERROR] >>> Entering show()" << std::endl;
    for (int i = 0; i < count; i++) {
        cout << queue[(i + front) % 10] << "\t";
    }
	std::cerr << "[WARN] <<< Exiting show()" << std::endl;
}

int main() {
	std::cerr << "[ERROR] >>> Entering main()" << std::endl;
    int ch, x;
    do {
        cout << "\n1. Enque";
        cout << "\n2. Deque";
        cout << "\n3. Print";
        cout << "\nEnter Your Choice : ";
        cin >> ch;
        if (ch == 1) {
            cout << "\nInsert : ";
            cin >> x;
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
