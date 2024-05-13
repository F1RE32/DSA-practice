#include <iostream>
using namespace std;

void selection_sort(int arr[], int size)
{
    for (int j = 0; j < size - 1; j++)
    {
        int mi = j;
        for (int i = j + 1; i < size; i++)
        {
            if (arr[i] < arr[mi])
            {
                mi = i;
            }
        }
        int t = arr[j];
        arr[j] = arr[mi];
        arr[mi] = t;
    }
}

void bubble_sort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int t = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = t;
            }
        }
    }
}

void insertion_sort(int arr[], int size)
{
    for (int i = 1; i < size; i++)
    {
        int j = i - 1;
        int hold = arr[j + 1];
        while (j >= 0 && hold < arr[j])
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = hold;
    }
}

int main()
{
    int size;
    cout << "Enter the size of array to be sorted" << " " ;
    cin >> size;
    int arr[size];
    cout << "Enter the elemets" << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    int select;
    cout << "Enter (1) for selection sort " << endl;
    cout << "Enter (2) for bubble sort " << endl;
    cout << "Enter (3) for insertion sort " << endl;
    cin >> select;

    if (select == 1){
        selection_sort(arr, size);
    }
    else if (select == 2) {
        bubble_sort(arr, size);
    }
    else if (select == 3){
        insertion_sort(arr, size);
    }
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
