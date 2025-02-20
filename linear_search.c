#include <stdio.h>

// Linear search function: returns the index of key if found, else -1.
int linearSearch(int a[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (a[i] == key) {
            return i;
        }
    }
    return -1;
}

int main() {
    // Example array
    int a[] = {10, 20, 30, 40, 50};
    int n = sizeof(a) / sizeof(a[0]);
    
    // Input key to search for
    int key;
    printf("Enter key to search: ");
    scanf("%d", &key);
    
    // Perform linear search
    int index = linearSearch(a, n, key);
    
    // Display the result
    if (index != -1) {
        printf("Key %d found at index %d.\n", key, index);
    } else {
        printf("Key %d not found in the array.\n", key);
    }
    
    return 0;
}
