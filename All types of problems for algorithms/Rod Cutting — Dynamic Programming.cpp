#include <iostream>
using namespace std;

int main() {

    int price[] = {1, 5, 8, 9, 10, 17, 17, 20};

    int n = 8;

    int dp[20] = {0};

    for (int i = 1; i <= n; i++) {

        int best = 0;

        for (int j = 1; j <= i; j++) {

            best = max(
                best,
                price[j - 1] + dp[i - j]
            );
        }

        dp[i] = best;
    }

    cout << "Maximum Profit = "
         << dp[n];

    return 0;
}
