#include <iostream>
using namespace std;

void swap(int arr[], int i, int j)
{
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

void maxheapify(int arr[], int size, int root)
{
	int initroot = root;
	int lc = 2*root + 1;
	int rc = 2*root + 2;
	
	if (lc<size && arr[lc]>arr[initroot])
	{
		initroot = lc;
	}
	
	if (rc<size && arr[rc]>arr[initroot])
	{
		initroot = rc;
	}
	
	if (initroot != root)
	{
		swap(arr, root, initroot);
		maxheapify(arr, size, initroot);
	}
}

void buildmaxheap(int arr[], int size)
{
    for (int i=size - 1; i >= 0; i--)
	{
	   maxheapify(arr, size, i);
	}
	
}
void printarray(int arr[], int size)
{
	for (int i=0; i<size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << "" << endl;
}

void del(int arr[], int size)
{
	
	swap(arr,size-1, 0);
	cout<<arr[0]<<","<<arr[size-1]<<endl;
	maxheapify(arr, size, 0);
}


void heapsort(int arr[], int size)
{
    for (int i = size - 1; i > 0; i--)
    {
        swap(arr, 0, i);
        maxheapify(arr, i, 0);
    }
}


int main()
{
	int arr[] = {2, 5, 72, 11, 9, 55};
	int size = sizeof(arr)/sizeof(int);
	buildmaxheap(arr,size);
	printarray(arr, size);
	heapsort(arr,size);
	printarray(arr, 6);
}
