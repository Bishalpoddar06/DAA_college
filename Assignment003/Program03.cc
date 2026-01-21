/*
Write the recursive code for Bubble Sort.
Calculate the time complexity using:
a) frequency count method
b) substitution method
*/

#include <iostream>
using namespace std;

// Recursive Bubble Sort
void recursiveBubbleSort(int arr[], int n) {
    if (n == 1)
        return;
    
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            swap(arr[i], arr[i + 1]);
        }
    }
    
    recursiveBubbleSort(arr, n - 1);
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    cout << "Original array: ";
    printArray(arr, n);
    
    recursiveBubbleSort(arr, n);
    
    cout << "Sorted array: ";
    printArray(arr, n);
    
    return 0;
}
/*
a) Frequency Count Method:
    - Outer recursive call: n times (n, n-1, n-2, ..., 1)
    - Inner loop iterations: (n-1) + (n-2) + ... + 1 = n(n-1)/2
    - Comparisons: n(n-1)/2 = O(n²)
    - Swaps (worst case): n(n-1)/2 = O(n²)
    - Total operations: O(n²)

b) Substitution Method:
    - T(n) = T(n-1) + (n-1)  [recursive relation]
    - T(1) = 1 (base case)
    - T(n) = T(n-1) + (n-1)
    -      = T(n-2) + (n-2) + (n-1)
    -      = T(1) + 1 + 2 + ... + (n-1)
    -      = 1 + n(n-1)/2
    -      = O(n²)
    
Time Complexity: O(n²) in all cases (best, average, worst)
Space Complexity: O(n) due to recursive call stack
*/
