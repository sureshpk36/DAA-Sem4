#include <iostream>
using namespace std;

// Function to partition the array using the first element as the pivot
int partition(int arr[], int low, int high) {
    int pivot = arr[low];  // Choosing the first element as pivot
    int i = low + 1;       // Index for the larger element
    int j = high;          // Index for the smaller element

    while (i <= j) {
        while (i <= high && arr[i] <= pivot)  // Find element greater than pivot
            i++;
        while (arr[j] > pivot)  // Find element smaller than pivot
            j--;

        if (i < j)
            swap(arr[i], arr[j]);  // Swap out-of-place elements
    }
    swap(arr[low], arr[j]);  // Swap pivot into correct position
    return j;
}

// QuickSort function
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high); // Get partition index

        quickSort(arr, low, pi - 1);  // Sort left partition
        quickSort(arr, pi + 1, high); // Sort right partition
    }
}

// Function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Main function
int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Unsorted Array: ";
    printArray(arr, n);

    quickSort(arr, 0, n - 1);

    cout << "Sorted Array: ";
    printArray(arr, n);

    return 0;
}
