#include <iostream>
using namespace std;

struct StudentRecord {
    int rollnumber;
    float gpa;
    StudentRecord* next;
};

void enqueue(StudentRecord** front, StudentRecord** rear) {
    StudentRecord* ptr = new StudentRecord;
    cout << "Insert Roll Number: ";
    cin >> ptr->rollnumber;
    cout << "Insert GPA: ";
    cin >> ptr->gpa;
    ptr->next = NULL;

    if (*front == NULL) {
        *front = *rear = ptr;  
    }
    else {
        (*rear)->next = ptr;  
        *rear = ptr;          
    }
}

void dequeue(StudentRecord** front, StudentRecord** rear) {
    if (*front == NULL) {
        cout << "Queue Underflow" << endl;  
        return;
    }

    StudentRecord* temp = *front;
    *front = (*front)->next;
    if (*front == NULL) {
        *rear = NULL;  
    }

    delete temp;  
}

void print(StudentRecord** front, StudentRecord** rear) {
    StudentRecord* curr = *front;
    while (curr != NULL) {
        cout << "Roll Number: " << curr->rollnumber << endl;
        cout << "GPA: " << curr->gpa << endl;
        cout << endl;
        curr = curr->next;
    }
}

int main() {
    StudentRecord* front = NULL;
    StudentRecord* rear = NULL;
    cout << "Queue is currently empty" << endl;

    int select = 0;
    cout << "Press 1 to enqueue" << endl;
    cout << "Press 2 to dequeue" << endl;
    cout << "Press 3 to print" << endl;
    cout << "Press 0 to exit" << endl;
    cout << "Enter your choice: ";
    cin >> select;

    while (select != 0) {
        switch (select) {
        case 1:
            enqueue(&front, &rear);
            break;
        case 2:
            dequeue(&front, &rear);
            break;
        case 3:
            print(&front, &rear);
            break;
        default:
            cout << "Invalid choice, try again." << endl;
        }
        cout << "Enter your choice again: ";
        cin >> select;
    }
}
