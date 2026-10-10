#include <iostream>
using namespace std;

int main() {

    int p[] = {10, 20, 30, 40, 30};

    int n = 5;

    int dp[5][5] = {0};

    for (int length = 2; length < n; length++) {

        for (int i = 1; i < n - length + 1; i++) {

            int j = i + length - 1;

            dp[i][j] = 999999;

            for (int k = i; k < j; k++) {

                int cost = dp[i][k]
                         + dp[k + 1][j]
                         + p[i - 1] * p[k] * p[j];

                dp[i][j] = min(dp[i][j], cost);
            }
        }
    }

    cout << "Minimum Multiplication = "
         << dp[1][n - 1];

    return 0;
}
