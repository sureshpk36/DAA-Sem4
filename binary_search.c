#include <stdio.h>

// Binary search function: returns the index of key if found, else -1.
int binarySearch(int a[], int key, int low, int high) {
    while (low <= high) {                // Changed condition to include low==high
        int mid = (low + high) / 2;
        if (a[mid] == key) {             // Use == for comparison instead of =
            return mid;
        } else if (a[mid] > key) {       // Corrected to 'else if'
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return -1;
}

int main() {
    // Example sorted array (binary search requires sorted arrays)
    int a[] = {10, 20, 30, 40, 50, 60, 70};
    int n = sizeof(a) / sizeof(a[0]);
    
    // Input key to search for
    int key;
    printf("Enter key to search: ");
    scanf("%d", &key);
    
    // Call binarySearch with low as 0 and high as n-1
    int index = binarySearch(a, key, 0, n - 1);
    
    // Display the result
    if (index != -1) {
        printf("Key %d found at index %d.\n", key, index);
    } else {
        printf("Key %d not found in the array.\n", key);
    }
    
    return 0;
}
