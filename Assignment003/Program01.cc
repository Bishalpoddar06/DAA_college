/*
Write the recursive code for Binary search.
Calculate the time complexity using:
a) frequency count method
b) substitution method
*/

#include <iostream>
using namespace std;

// Recursive Binary Search
int binarySearch(int arr[], int low, int high, int target) {
    if (low > high) {
        return -1; 
    }
    
    int mid = low + (high - low) / 2;
    
    if (arr[mid] == target) {
        return mid;  
    }
    else if (arr[mid] > target) {
        return binarySearch(arr, low, mid - 1, target);  
    }
    else {
        return binarySearch(arr, mid + 1, high, target);  
    }
}

int main() {
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 45, 56, 67};
    int n = 10;
    int target = 23;
    
    int result = binarySearch(arr, 0, n - 1, target);
    
    if (result != -1) {
        cout << "Element found at index: " << result << endl;
    } else {
        cout << "Element not found" << endl;
    }
    
    return 0;
}

/*
a) Frequency Count Method:
    - Base case (low > high): 1 comparison
    - Recursive case: 1 mid calculation + 1 comparison + 1 recursive call
    - Each recursion reduces search space by half
    - Maximum depth: log₂(n)
    - Total operations: O(log n)

b) Substitution Method:
    T(n) = T(n/2) + 1
    
    Assume T(n) = O(log n)
    T(n) = T(n/2) + 1
          = T(n/4) + 1 + 1
          = T(n/8) + 1 + 1 + 1
          ...
          = T(1) + log₂(n)
          = O(log n)
    
    Therefore, Time Complexity: O(log n)
    Space Complexity: O(log n) due to recursion stack
*/