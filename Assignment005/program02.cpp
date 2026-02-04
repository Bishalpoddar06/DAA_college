#include <iostream>
using namespace std;

void insertionSort(int arr[], int n) {
    // for loop: runs n-1 times = O(n)
    for (int i = 1; i < n; i++) {
        int key = arr[i];  // O(1)
        int j = i - 1;  // O(1)
        
        // while loop: runs 0 to i times in worst case = O(i) = O(n) total across all iterations
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];  // O(1)
            j--;  // O(1)
        }
        arr[j + 1] = key;  // O(1)
    }
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);  // O(1)
    
    insertionSort(arr, n);  // O(n²)
    
    cout << "Sorted array: ";  // O(1)
    for (int i = 0; i < n; i++)  // O(n)
        cout << arr[i] << " ";  // O(1)
    cout << endl;  // O(1)
    
    return 0;  // O(1)
}
// TIME COMPLEXITY ANALYSIS - SUBSTITUTION METHOD
// ============================================
/*
Let T(n) = time to sort array of size n

T(n) = T(n-1) + n  (for worst case)
    = T(n-1) + n
    = T(n-2) + (n-1) + n
    = T(n-3) + (n-2) + (n-1) + n
    ...
    = T(1) + 2 + 3 + ... + n
    = 1 + 2 + 3 + ... + n
    = n(n+1)/2
    = (n² + n)/2
    = O(n²)
*/

// TIME COMPLEXITY ANALYSIS - FREQUENCY METHOD
// ============================================
/*
Statement                          Frequency    Time
for (int i = 1; i < n; i++)            n        O(n)
    int key = arr[i];                n-1        O(n-1)
    int j = i - 1;                   n-1        O(n-1)
    
    while (j >= 0 && arr[j] > key)   Σ(i)       O(n²)
       arr[j + 1] = arr[j];         Σ(i)       O(n²)
       j--;                         Σ(i)       O(n²)
    
    arr[j + 1] = key;                n-1        O(n-1)

Total = n + (n-1) + (n-1) + Σ(i=1 to n-1) i + Σ(i=1 to n-1) i + (n-1)
     = 3n - 3 + 2*[n(n-1)/2]
     = 3n - 3 + n² - n
     = n² + 2n - 3
     = O(n²)  [Dominant term is n²]
*/
