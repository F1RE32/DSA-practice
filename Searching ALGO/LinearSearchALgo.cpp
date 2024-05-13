#include <iostream>
using namespace std;

int linearSearch(int arr[], int size, int key) {
	for (int i = 0; i < size; i++) {
		if (arr[i] == key) {
			return i;
		}
	}

	return -1;
}

int main() {
	cout << "Linear Search By Sajjad Tariq\n";
	int size;
	int key;


	cout << "Enter size of array: ";
	cin >> size;

	int* array = new int[size];

	cout << "Enter elements of array: ";
	for (int i = 0; i < size; ++i) {
		cin >> array[i];
	}


	cout << "Enter key: ";
	cin >> key;

	int result = linearSearch(array, size, key);

	if (result != -1) {
		cout << "Key found at index: " << result << endl;
	}
	else {
		cout << "Key not found in the array." << endl;
	}

	return 0;
}