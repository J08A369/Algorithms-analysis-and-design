#include <iostream>
using namespace std;

int main() {

    string X = "ABCBDAB";
    string Y = "BDCAB";

    int m = X.length();
    int n = Y.length();

    int dp[20][20] = {0};

    for (int i = 1; i <= m; i++) {

        for (int j = 1; j <= n; j++) {

            if (X[i - 1] == Y[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;

            else
                dp[i][j] =
                    max(dp[i - 1][j],
                        dp[i][j - 1]);
        }
    }

    cout << "LCS Length = "
         << dp[m][n];

    return 0;
}
