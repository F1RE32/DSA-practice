#include <iostream>
using namespace std;

const int QUEUE_SIZE = 6;

void EnQueue(int* front, int* rear, int queue[]) {
    if ((*rear + 1) % QUEUE_SIZE == *front) {
        cout << "\nQueue overflow" << endl;
    }
    else {
        cout << "\nEnter value: ";
        cin >> queue[*rear];
        *rear = (*rear + 1) % QUEUE_SIZE;  // Wrap around if necessary
    }
}

void DeQueue(int* front, int* rear, int queue[]) {
    if (*front == *rear) {
        cout << "\nQueue underflow" << endl;
    }
    else {
        cout << "\nDequeued: " << queue[*front] << endl;
        *front = (*front + 1) % QUEUE_SIZE;  // Move front forward and wrap around if necessary
    }
}

void PrintQueue(int* front, int* rear, int queue[]) {
    if (*front == *rear) {
        cout << "\nQueue is empty" << endl;
        return;
    }
    cout << "\nQueue elements:" << endl;
    int i = *front;
    while (i != *rear) {
        cout << queue[i] << " ";
        i = (i + 1) % QUEUE_SIZE;  // Move to next element and wrap around if necessary
    }
    cout << endl;
}

int main() {
    int queue[QUEUE_SIZE] = { 0 }; // Initialize queue with zeros
    int front = 0, rear = 0;
    int n = 1;

    cout << "Queue is currently empty" << endl;
    cout << "Press 1 to insert value" << endl;
    cout << "Press 2 to delete value" << endl;
    cout << "Press 3 to print" << endl;
    cout << "Press 0 to exit" << endl;

    while (n != 0) {
        cout << "Enter your choice: ";
        cin >> n;

        switch (n) {
        case 1:
            EnQueue(&front, &rear, queue);
            break;
        case 2:
            DeQueue(&front, &rear, queue);
            break;
        case 3:
            PrintQueue(&front, &rear, queue);
            break;
        default:
            if (n != 0) cout << "Invalid input, please try again." << endl;
            break;
        }
    }
    return 0;
}
