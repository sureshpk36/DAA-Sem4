#include <iostream>
using namespace std;

// Function to perform insertion sort
void insertionSort(int a[], int n) {
    int i, j, key;
    for (i = 1; i < n; i++) {
        key = a[i];
        j = i - 1;

        // Move elements that are greater than key one position ahead
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;  // Insert the key at the correct position
    }
}

// Function to print the array
void printArray(int a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

// Main function
int main() {
    int a[] = {12, 11, 13, 5, 6};
    int n = sizeof(a) / sizeof(a[0]);

    cout << "Unsorted Array: ";
    printArray(a, n);

    insertionSort(a, n);

    cout << "Sorted Array: ";
    printArray(a, n);

    return 0;
}
