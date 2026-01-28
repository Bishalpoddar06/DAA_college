/*
Write the code for-
3. Matrix multiplication of 2 square matrix 
Complexity
Find the recurrence relation first followed by substituition method
*/

#include <iostream>
using namespace std;

const int MAX = 3;

void multiplyMatrix(int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = 0;
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void displayMatrix(int matrix[MAX][MAX], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }
}

int main() {
    int n = 3;
    int A[MAX][MAX] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    
    int B[MAX][MAX] = {
        {9, 8, 7},
        {6, 5, 4},
        {3, 2, 1}
    };
    
    int C[MAX][MAX];
    
    multiplyMatrix(A, B, C, n);
    
    cout << "Matrix A:\n";
    displayMatrix(A, n);
    
    cout << "\nMatrix B:\n";
    displayMatrix(B, n);
    
    cout << "\nResult (A × B):\n";
    displayMatrix(C, n);
    
    return 0;
}

/*
RECURRENCE RELATION:
For standard matrix multiplication (3 nested loops):
T(n) = 8*T(n/2) + O(n²)  [Divide & Conquer approach]
OR
T(n) = O(n³)  [Direct approach]

SUBSTITUTION METHOD (for T(n) = 8*T(n/2) + n²):
Assume T(n) = cn³

T(n) = 8*T(n/2) + n²
     = 8*c(n/2)³ + n²
     = 8*c*n³/8 + n²
     = c*n³ + n²

Since c*n³ dominates n², we get T(n) = Θ(n³)

DIRECT APPROACH:
Three nested loops, each running n times
Time Complexity: Θ(n³)
Space Complexity: Θ(n²)
*/