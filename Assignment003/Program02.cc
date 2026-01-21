/*
Write the iterative code for Binary search.
Calculate the time complexity using
a) frequency count method
b) substitution method
*/
#include <iostream>
using namespace std;

// Iterative Binary search
int binarySearch(int arr[], int n, int target) {
    int left = 0, right = n - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

int main() {
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 45, 56, 67};
    int n = 10;
    int target = 23;
    
    int result = binarySearch(arr, n, target);
    
    if (result != -1)
        cout << "Element found at index: " << result << endl;
    else
        cout << "Element not found" << endl;
    
    return 0;
}

/*
TIME COMPLEXITY ANALYSIS:

a) FREQUENCY COUNT METHOD:
    Operations in binarySearch():
    - Assignment (left = 0, right = n-1): 2 times (outside loop)
    - while condition check: O(log n) times
    - mid calculation: O(log n) times
    - Comparisons (arr[mid] == target, arr[mid] < target): O(log n) times
    - left/right updates: O(log n) times
    
    Total: O(log n) dominant term
    Time Complexity: O(log n)

b) SUBSTITUTION METHOD:
    Let T(n) = time for searching in array of size n
    
    At each iteration, the search space is halved:
    T(n) = T(n/2) + c  (where c is constant for comparisons)
    
    Expanding:
    T(n) = T(n/2) + c
          = T(n/4) + c + c
          = T(n/8) + c + c + c
          = ... (repeat log n times until n becomes 1)
          = T(1) + c*log(n)
          = O(1) + O(log n)
    
    Time Complexity: O(log n)
*/