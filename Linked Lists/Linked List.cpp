#include <iostream>
#include <stdlib.h>
using namespace std;

struct studentRecord
{
    int rollnumber;
    float gpa;
    int index;
    studentRecord* next;
};

// void insert(studentRecord** head)
// {
//     studentRecord* ptr = (studentRecord*)malloc(sizeof(studentRecord));
//     cout << "Insert Roll Number: ";
//     cin >> ptr->rollnumber;
//     cout << "Insert GPA: ";
//     cin >> ptr->gpa;
//     ptr->next = NULL;
//     if (*head == NULL)
//     {
//         *head = ptr;
//     }
//     else
//     {
//         studentRecord* curr = *head;
//         while (curr->next != NULL)
//         {
//             curr = curr->next;
//         }
//         curr->next = ptr;
//     }
// }

bool insert(studentRecord** head)
{
    studentRecord* ptr = (studentRecord*)malloc(sizeof(studentRecord));
    cout << "Insert Roll Number: ";
    cin >> ptr->rollnumber;
    cout << "Insert GPA: ";
    cin >> ptr->gpa;
    ptr->next = NULL;
    if (*head == NULL)
    {
        *head = ptr;
        return true;
    }
    if (ptr->rollnumber < (*head)->rollnumber)
    {
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
                ptr->next = cnext;
                return true;
            }
            else
            {
                curr = cnext ;
                cnext = cnext->next;
            }
        }
            curr->next = ptr;
            return false;
    }
}
//     else
//     {
//          studentRecord* curr = *head;
//           while (curr->next != NULL)
//           {
//               curr = curr->next;
//           }
//           curr->next = ptr;
//     }


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
    studentRecord* curr = *head;
    int toDelete;
    cout << "Insert Roll Number: ";
    cin >> toDelete;
    if (toDelete == (*head)->rollnumber)
    {
        *head = (*head)->next;
        free(curr);
    }
    else
    {
        studentRecord* prev = (*head);
        curr = (*head)->next;
        while (curr != NULL)
        {
            if (curr->rollnumber == toDelete)
            {
                prev->next = curr->next;
                free(curr);
                break;
            }
            else
            {
                curr = curr->next;
                prev = prev->next;
            }
        }
        if (curr->next == NULL)
        {
            cout << "Doesn't Exist";
        }
    }
}

void delall(studentRecord** head)
{
    studentRecord* curr = *head;
    while (curr != NULL)
    {
        *head = curr->next;
        free(curr);
        curr = *head;
    }
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

void printbyindex(studentRecord** head)
{
    int pbi;
    cout << "Enter Index: ";
    cin >> pbi;
    int index = 0;
    studentRecord* curr = *head;
    while (curr != NULL)
    {
        if (pbi == index)
        {
            cout << "Roll Number: " << curr->rollnumber << endl;
            cout << "GPA: " << curr->gpa << endl;
        }
        index++;
        curr = curr->next;
    }
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
        if (select == 7)
        {
            printbyindex(&head);
        }

        cout << "Enter your choice again: "
            << "";
        cin >> select;
    }
}
