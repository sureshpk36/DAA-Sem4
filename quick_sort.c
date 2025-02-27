#include <iostream>
using namespace std;

// Function to partition the array using the first element as the pivot
int partition(int arr[], int low, int high) {
    int pivot = arr[low];  
    int j = high;

    for (int i = low + 1; i <= j; i++) {
        if (arr[i] > pivot) {  
            swap(arr[i], arr[j]);
            j--;
            i--;  // Recheck swapped element
        }
    }
    swap(arr[low], arr[j]);  
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
