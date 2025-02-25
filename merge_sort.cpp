#include <iostream>
#include <vector>
using namespace std;

void merge(int arr[], int si, int mid, int ei) {
    vector<int> temp;
    int i = si, j = mid + 1;
    
    // Merge the two subarrays into temp
    while (i <= mid && j <= ei) {
        if (arr[i] < arr[j]) {
            temp.push_back(arr[i]);
            i++;
        } else {
            temp.push_back(arr[j]);
            j++;
        }
    }
    
    // Copy any remaining elements from the left subarray
    while (i <= mid) {
        temp.push_back(arr[i]);
        i++;
    }
    
    // Copy any remaining elements from the right subarray
    while (j <= ei) {
        temp.push_back(arr[j]);
        j++;
    }
    
    // Copy back from temp to the original array
    for (int k = si, x = 0; k <= ei; k++, x++) {
        arr[k] = temp[x];
    }
}

void mergeSort(int arr[], int si, int ei) {
    if (si >= ei) {
        return;
    }
    int mid = si + (ei - si) / 2;
    mergeSort(arr, si, mid);
    mergeSort(arr, mid + 1, ei);
    merge(arr, si, mid, ei);
}

int main() {
    int arr[] = {5, 2, 8, 3, 9, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    mergeSort(arr, 0, n - 1);
    
    // Print sorted array
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    return 0;
}
