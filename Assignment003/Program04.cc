/*
Write the Iterative code for Bubble Sort.
Calculate the time complexity using:
a) frequency count method
b) substitution method
*/
#include <iostream>
using namespace std;

// Iterative Bubble Sort
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
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
    
    bubbleSort(arr, n);
    
    cout << "Sorted array: ";
    printArray(arr, n);
    
    return 0;
}

/*
TIME COMPLEXITY ANALYSIS OF BUBBLE SORT

a) FREQUENCY COUNT METHOD:
    Line 6:  for (int i = 0; i < n - 1; i++)           → Executes n times
    Line 7:  for (int j = 0; j < n - i - 1; j++)       → Executes n-1 times (avg)
    Line 8:  if (arr[j] > arr[j + 1])                  → Executes (n-1)*(n-1) times
    Line 10-12: Swap operations                          → Executes at most (n-1)*(n-1) times
    
    Total comparisons: (n-1) + (n-2) + ... + 1 = n(n-1)/2 ≈ n²/2
    Total operations: O(n²)

b) SUBSTITUTION METHOD:
    T(n) = T(n-1) + (n-1)
    
    Expanding:
    T(n) = T(n-1) + (n-1)
    T(n) = T(n-2) + (n-2) + (n-1)
    T(n) = T(n-3) + (n-3) + (n-2) + (n-1)
    ...
    T(n) = T(1) + 1 + 2 + 3 + ... + (n-1)
    T(n) = 1 + Σ(i=1 to n-1) i
    T(n) = 1 + (n-1)n/2
    T(n) = (n² - n + 2)/2
    
    Time Complexity: O(n²)
    Space Complexity: O(1)
*/
