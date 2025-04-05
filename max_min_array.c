#include <stdio.h>

// Function to find maximum and minimum in array using divide and conquer
void findMaxMin(int arr[], int low, int high, int *max, int *min) {
    int mid, max1, min1, max2, min2;

    // If only one element
    if (low == high) {
        *max = *min = arr[low];
        return;
    }

    // If only two elements
    if (high == low + 1) {
        if (arr[low] > arr[high]) {
            *max = arr[low];
            *min = arr[high];
        } else {
            *max = arr[high];
            *min = arr[low];
        }
        return;
    }

    // Divide the array
    mid = (low + high) / 2;

    // Find max and min in left half
    findMaxMin(arr, low, mid, &max1, &min1);

    // Find max and min in right half
    findMaxMin(arr, mid + 1, high, &max2, &min2);

    // Combine results
    *max = (max1 > max2) ? max1 : max2;
    *min = (min1 < min2) ? min1 : min2;
}

int main() {
    int arr[] = {10, 5, 20, 8, 25, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int max, min;

    findMaxMin(arr, 0, n - 1, &max, &min);

    printf("Maximum element: %d\n", max);
    printf("Minimum element: %d\n", min);

    return 0;
}
