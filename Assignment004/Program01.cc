/*
Write the code for-
1. Quick Sort 
Complexity
Find the recurrence relation first followed by substituition method
*/

#include <iostream>
using namespace std;

int partition(int arr[], int low, int high);
void quickSort(int arr[], int low, int high);
void printArray(int arr[], int n);

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    cout << "Original array: ";
    printArray(arr, n);
    
    quickSort(arr, 0, n - 1);
    
    cout << "Sorted array: ";
    printArray(arr, n);
    
    return 0;
}

/*
=== COMPLEXITY ANALYSIS ===

1. RECURRENCE RELATION:
   T(n) = T(k) + T(n-k-1) + O(n)
   where k is the partition point (0 to n-1)
   O(n) is for partitioning operation
   
2. SUBSTITUTION METHOD:

   Case 1: BEST CASE (Balanced Partition)
   When partition splits array in half:
   T(n) = T(n/2) + T(n/2) + O(n)
   T(n) = 2*T(n/2) + O(n)
   
   Guess: T(n) = O(n log n)
   
   Proof:
   T(n) = 2*T(n/2) + cn
   Assume T(k) = ck log k for k < n
   T(n) = 2*c(n/2)*log(n/2) + cn
        = cn*log(n/2) + cn
        = cn*(log n - log 2) + cn
        = cn*log n - cn + cn
        = cn*log n
    Verified: T(n) = O(n log n)
*/