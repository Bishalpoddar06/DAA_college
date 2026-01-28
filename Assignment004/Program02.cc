/*
Write the code for-
2. Merge Sort
Complexity
Find the recurrence relation first followed by substituition method
*/

#include <iostream>
using namespace std;

void merge(int arr[], int left, int mid, int right) {
    int temp[right - left + 1];
    int i = left, j = mid + 1, k = 0;
    
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }
    
    while (i <= mid) temp[k++] = arr[i++];
    while (j <= right) temp[k++] = arr[j++];
    
    for (i = left, k = 0; i <= right; i++, k++)
        arr[i] = temp[k];
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main() {
    int arr[] = {38, 27, 43, 3, 9, 82, 10};
    int n = 7;
    
    cout << "Original: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << "\n";
    
    mergeSort(arr, 0, n - 1);
    
    cout << "Sorted: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << "\n";
    
    return 0;
}

/*
RECURRENCE RELATION:
T(n) = 2T(n/2) + n

SUBSTITUTION METHOD (Proof):
T(n) = 2T(n/2) + n
     = 2[2T(n/4) + n/2] + n = 4T(n/4) + 2n
     = 4[2T(n/8) + n/4] + 2n = 8T(n/8) + 3n
     ...
     = 2^k T(n/2^k) + kn

At k = log(n): n/2^k = 1
T(n) = n·T(1) + n·log(n) = O(n log n)

TIME COMPLEXITY: O(n log n) - best, average, worst
*/