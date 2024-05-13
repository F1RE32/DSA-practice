#include <iostream>
#include <stdlib.h>
using namespace std;

struct studentRecord
{
    int rollnumber;
    float gpa;
    studentRecord* next;
};

void push(studentRecord** top)
{
    studentRecord* ptr = (studentRecord*)malloc(sizeof(studentRecord));
    cout << "Insert Roll Number: ";
    cin >> ptr->rollnumber;
    cout << "Insert GPA: ";
    cin >> ptr->gpa;
    ptr->next = NULL;
    if (top == NULL)
    {
        *top = ptr;
    }
    else
    {
        studentRecord* curr = *top;
        ptr->next = curr;
        *top = ptr;
    }
}

void print(studentRecord** top)
{
    studentRecord* curr = *top;
    while (curr != NULL)
    {
        cout << "Roll Number: " << curr->rollnumber << endl;
        cout << "GPA: " << curr->gpa << endl;
        cout << "" << endl;
        curr = curr->next;
    }
}

void pop(studentRecord** top)
{
	studentRecord* curr = *top;
	if (curr != NULL)
	{
	if (curr->next == NULL)
	{
		free(curr);
		cout << "List is now empty"<< endl;
		*top = NULL;
	}
	else
	{
		*top = (*top)->next;
		free(curr);
	}
	}
	else
	{
		cout << "Stack Underflow" << endl;
	}
}

int main()
{
    studentRecord* top = NULL;
    cout << "List is currently empty" << endl;
    push(&top);
    cout << "Press 1 to push" << endl;
    cout << "Press 2 to pop" << endl;
    cout << "Press 3 to print" << endl;
    cout << "Press 0 to exit" << endl;
    cout << "Enter your choice: " << "";
    int select = 1;
    cin >> select;
    while (select != 0)
    {
        if (select == 1)
        {
            push(&top);
        }
        if (select == 2)
        {
            pop(&top);
        }
        if (select == 3)
        {
            print(&top);
        }
        
        cout << "Enter your choice again: "<< "";
        cin >> select;
    }
}
