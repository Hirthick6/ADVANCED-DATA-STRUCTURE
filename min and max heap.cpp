//MIN AND MAX HEAP
// C++ program to insert new element to Heap

#include <iostream>
using namespace std;
#define MAX 1000 // Max size of Heap

// Function to heapify ith node in a Heap
// of size n following a Bottom-up approach
void insert_heapify(int arr[], int n, int i)
{
	if(i!=0)
	{
	// Find parent
	int parent = (i - 1) / 2;
		// For Max-Heap
		// If current node is greater than its parent
		// Swap both of them and call heapify again
		// for the parent
		if (arr[i] > arr[parent])
			swap(arr[i], arr[parent]);

			// Recursively heapify the parent node

			insert_heapify(arr, n, parent);
		}
		}



// Function to insert a new node to the Heap
void insertNode(int arr[], int& n, int Key)
{


	// Insert the element at end of Heap
	arr[n ] = Key;
    // Increase the size of Heap by 1
	n = n + 1;
	// Heapify the new node following a
	// Bottom-up approach
	insert_heapify(arr, n, n - 1);
}

void delete_heapify(int arr[], int n, int i)
{
	int largest = i; // Initialize largest as root
	int l = 2 * i + 1; // left = 2*i + 1
	int r = 2 * i + 2; // right = 2*i + 2

	// If left child is larger than root
	if (l < n && arr[l] > arr[largest])
		largest = l;

	// If right child is larger than largest so far
	if (r < n && arr[r] > arr[largest])
		largest = r;

	// If largest is not root
	if (largest != i) {
		swap(arr[i], arr[largest]);

		// Recursively heapify the affected sub-tree
		delete_heapify(arr, n, largest);
	}
}
// Function to delete the root from Heap
void deleteRoot(int arr[], int& n)
{
	// Get the last element
	int lastElement = arr[n - 1];

	// Replace root with last element
	arr[0] = lastElement;

	// Decrease size of heap by 1
	n = n - 1;

	// heapify the root node
	delete_heapify(arr, n, 0);
}

// A utility function to print array of size n
void printArray(int arr[], int n)
{
	for (int i = 0; i < n; ++i)
		cout << arr[i] << " ";

	cout << "\n";
}

// Driver Code
int main()
{
	int arr[MAX];

	int n = 0;

	insertNode(arr, n, 10);
	insertNode(arr, n, 5);
	insertNode(arr, n, 3);
	insertNode(arr, n, 1);
	insertNode(arr, n, 16);
	printArray(arr, n);

    deleteRoot(arr, n);
    printArray(arr, n);

    deleteRoot(arr, n);
	printArray(arr, n);

	return 0;
}
