#include <stdio.h>

// Swap two elements in the array
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition the array using the last element as the pivot.
// After partitioning, all elements less than the pivot are on its left,
// and all elements greater than the pivot are on its right.
int partition(int arr[], int low, int high) {
    int pivot = arr[high];  // Choose the last element as the pivot
    int i = low - 1;        // Index of the smaller element

    // Move elements that are less than the pivot to the left side
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;              // Increase index for smaller elements
            swap(&arr[i], &arr[j]);  // Swap current element with the element at index i
        }
    }
    // Place the pivot in its correct position
    swap(&arr[i + 1], &arr[high]);
    return i + 1;  // Return the index of the pivot
}

// Quick Sort function that recursively sorts the array.
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // Partition the array and get the pivot index
        int p = partition(arr, low, high);
        
        // Recursively sort elements before and after the pivot
        quickSort(arr, low, p - 1);
        quickSort(arr, p + 1, high);
    }
}

int main() {
    // Define an array to be sorted
    int arr[] = {9, 4, 7, 3, 6, 2, 8, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);  // Calculate the number of elements
    
    // Call quickSort to sort the array
    quickSort(arr, 0, n - 1);
    
    // Print the sorted array
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}
