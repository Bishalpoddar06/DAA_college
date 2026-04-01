/*
Matrix Chain Multiplication using Dynamic Programming.
*/
#include <iostream>
#include <limits>
using namespace std;

int main() {
    int n;
    cout << "Enter number of matrices: ";
    cin >> n;

    int* dims = new int[n + 1];

    cout << "Enter " << n + 1 << " dimensions: ";
    for (int i = 0; i <= n; i++) {
        cin >> dims[i];
    } 
    long long** dp = new long long*[n + 1];
    for (int i = 0; i <= n; i++) {
        dp[i] = new long long[n + 1];
    }
     for (int i = 1; i <= n; i++) {
        dp[i][i] = 0;
    }
    for (int length = 2; length <= n; length++) {
        for (int i = 1; i <= n - length + 1; i++) {
            int j = i + length - 1;
            dp[i][j] = numeric_limits<long long>::max();

            for (int k = i; k < j; k++) {
                long long cost = dp[i][k] + dp[k + 1][j]
                    + (long long)dims[i - 1] * dims[k] * dims[j];

                if (cost < dp[i][j]) {
                    dp[i][j] = cost;
                }
            }
        }
    }
    cout << "Minimum number of scalar multiplications: " << dp[1][n] << endl;
    for (int i = 0; i <= n; i++) {
        delete[] dp[i];
    }
    delete[] dp;
    delete[] dims;

    return 0;
}

/*
OUTPUT:
Enter number of matrices: 3
Enter 4 dimensions: 10 40 35 50
Minimum number of scalar multiplications: 31500
*/