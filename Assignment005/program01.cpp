#include <iostream>              // O(1)
using namespace std;             // O(1)

void selectionSort(int arr[], int n) {   // O(1)
    for (int i = 0; i < n - 1; i++) {     // Runs (n − 1) times → O(n)
        int minIdx = i;                  // O(1) per iteration

        for (int j = i + 1; j < n; j++) {// Runs (n − i − 1) times
            if (arr[j] < arr[minIdx])    // O(1)
                minIdx = j;              // O(1)
        }

        swap(arr[i], arr[minIdx]);       // O(1)
    }
}

int main() {                             // O(1)
    int arr[] = {64, 34, 25, 12, 22, 11, 90}; // O(1)
    int n = 7;                           // O(1)
    
    selectionSort(arr, n);               // O(n²)
    
    cout << "Sorted array: ";            // O(1)
    for (int i = 0; i < n; i++)           // O(n)
        cout << arr[i] << " ";            // O(1)
    
    return 0;                            // O(1)
}
// TIME COMPLEXITY ANALYSIS USING SUBSTITUTION METHOD
// ====================================================
// For selectionSort(int arr[], int n):
// T(n) = (n-1) + (n-2) + (n-3) + ... + 1
// T(n) = Σ(i=1 to n-1) i
// T(n) = (n-1)×n/2
// T(n) = (n² - n)/2
// T(n) = O(n²)

// TIME COMPLEXITY ANALYSIS USING FREQUENCY METHOD
// ================================================
// Statement                          | Frequency  | Cost
// int minIdx = i;                    | (n-1)      | O(1)
// if (arr[j] < arr[minIdx])          | Σ(n-i-1)   | O(1)
// minIdx = j;                        | ≤ Σ(n-i-1) | O(1)
// swap(arr[i], arr[minIdx]);         | (n-1)      | O(1)
//
// Total comparisons: (n-1) + (n-2) + ... + 1 = n(n-1)/2
// Total assignments: ≤ n(n-1)/2
// Total swaps: (n-1)
//
// Overall: T(n) = n(n-1)/2 + n(n-1)/2 + (n-1)
//          T(n) = n² - n + O(n)
//          T(n) = O(n²)
//

