#include <iostream>
#include <stdlib.h>
using namespace std;


struct studentRecord
{
    int rollnumber;
    float gpa;
    studentRecord* next;
    studentRecord* prev;
};


//void insert(studentRecord** head)
//{
//    studentRecord* ptr = (studentRecord*)malloc(sizeof(studentRecord));
//    cout << "Insert Roll Number: ";
//    cin >> ptr->rollnumber;
//    cout << "Insert GPA: ";
//    cin >> ptr->gpa;
//    ptr->next = NULL;
//    ptr->prev = NULL;
//    if (*head == NULL)
//    {
//        *head = ptr;
//    }
//    else
//    {
//        studentRecord* curr = *head;
//        while (curr->next != NULL)
//        {
//            curr = curr->next;
//        }
//        curr->next = ptr;
//        ptr->prev = curr;
//    }
//}

bool insert(studentRecord** head)
{
    studentRecord* ptr = (studentRecord*)malloc(sizeof(studentRecord));
    cout << "Insert Roll Number: ";
    cin >> ptr->rollnumber;
    cout << "Insert GPA: ";
    cin >> ptr->gpa;
    ptr->next = NULL;
    ptr->prev = NULL;
    if (*head == NULL)
    {
        *head = ptr;
        return true;
    }
    if (ptr->rollnumber < (*head)->rollnumber)
    {
        (*head)->prev = ptr;
        ptr->next = *head;
        *head = ptr;
        return true;
    }
    if (ptr->rollnumber > (*head)->rollnumber)
    {
        studentRecord* curr = *head;
        studentRecord* cnext = curr->next;
        while (cnext != NULL)
        {
            if (ptr->rollnumber < cnext->rollnumber)
            {
                curr->next = ptr;
                cnext->prev = ptr;
                ptr->prev = curr;
                ptr->next = cnext;
                return true;
            }
            else
            {
                curr = cnext;
                cnext = cnext->next;
            }
        }
        curr->next = ptr;
        ptr->prev = curr;
        return false;
    }
}

void search(studentRecord** head)
{
    int toSearch;
    cout << "Enter student's rollnumber: ";
    cin >> toSearch;


    studentRecord* curr = *head;
    while (curr != NULL)
    {
        if (curr->rollnumber == toSearch)
        {
            cout << "Roll Number: " << curr->rollnumber << endl;
            cout << "GPA: " << curr->gpa << endl;
            break;
        }
        else
        {
            curr = curr->next;
            if (curr == NULL) {
                cout << "Element doesn't exist" << endl;
                break;
            }
        }
    }
}


void print(studentRecord** head)
{
    studentRecord* curr = *head;
    while (curr != NULL)
    {
        cout << "Roll Number: " << curr->rollnumber << endl;
        cout << "GPA: " << curr->gpa << endl;
        cout << "" << endl;
        curr = curr->next;
    }
}


void del(studentRecord** head)
{
    int toDelete;
    cout << "Insert Roll Number: ";
    cin >> toDelete;


    studentRecord* curr = *head;
    while (curr != NULL)
    {
        if (curr->rollnumber == toDelete)
        {
            if (curr->prev != NULL)
            {
                curr->prev->next = curr->next;
            }
            if (curr->next != NULL)
            {
                curr->next->prev = curr->prev;
            }
            if (curr == *head)
            {
                *head = curr->next;
            }
            free(curr);
            return;
        }
        curr = curr->next;
    }
    cout << "Doesn't Exist" << endl;
}


void delall(studentRecord** head)
{
    studentRecord* curr = *head;
    while (curr != NULL)
    {
        studentRecord* temp = curr->next;
        free(curr);
        curr = temp;
    }
    *head = NULL;
}

void count(studentRecord** head)
{
    int count = 0;
    studentRecord* curr = *head;
    while (curr != NULL)
    {
        count++;
        curr = curr->next;
    }
    cout << "Total number of elements in the list are " << count << endl;
}

int main()
{
    studentRecord* head = NULL;
    cout << "List is currently empty" << endl;
    insert(&head);
    int select = 1;
    cout << "Press 1 to insert" << endl;
    cout << "Press 2 to search" << endl;
    cout << "Press 3 to print" << endl;
    cout << "Press 4 to delete" << endl;
    cout << "Press 5 to delete all" << endl;
    cout << "Press 6 to print the total number of elements" << endl;
    cout << "Press 0 to exit" << endl;
    cout << "Enter your choice: " << "";
    cin >> select;
    while (select != 0)
    {
        if (select == 1)
        {
            insert(&head);
        }
        if (select == 2)
        {
            search(&head);
        }
        if (select == 3)
        {
            print(&head);
        }
        if (select == 4)
        {
            del(&head);
        }
        if (select == 5)
        {
            delall(&head);
        }
        if (select == 6)
        {
            count(&head);
        }

        cout << "Enter your choice again: "
            << "";
        cin >> select;
    }
}