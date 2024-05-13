#include <iostream>
using namespace std;

int binarySearch(int* arr, int size, int key) {
    int left = 0, right = size - 1;

    while (left <= right) {
       
        int mid = (left + right) / 2;

        if (arr[mid] == key) {
            return mid; 
        }
        else if (arr[mid] < key) {
            left = mid + 1; 
        }
        else {
        right = mid - 1; 
        }
    }

    return -1; 
}

int main() {
    cout << "Binary Search Implementation\n";

    int size, key;
    cout << "Enter size of sorted array: ";
    cin >> size;

    if (size <= 0) {
        cout << "Array size must be positive." << endl;
        return 1;
    }

    int* array = new int[size];

    cout << "Enter elements of sorted array: ";
    for (int i = 0; i < size; ++i) {
        cin >> array[i];
    }

    cout << "Enter key to find: ";
    cin >> key;

    int result = binarySearch(array, size, key);

    if (result != -1) {
        cout << "Key found at index: " << result << endl;
    }
    else {
        cout << "Key not found in the array." << endl;
    }
    return 0;
}
