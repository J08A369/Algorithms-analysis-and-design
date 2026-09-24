#include <iostream>
using namespace std;

int main() {

    int coins[] = {1, 2, 5};
    int n = 3;

    int amount = 11;

    int dp[100];

    for (int i = 0; i <= amount; i++)
        dp[i] = 9999;

    dp[0] = 0;

    for (int i = 1; i <= amount; i++) {

        for (int j = 0; j < n; j++) {

            if (coins[j] <= i) {

                dp[i] = min(
                    dp[i],
                    dp[i - coins[j]] + 1
                );
            }
        }
    }

    cout << "Minimum Coins = "
         << dp[amount];

    return 0;
}
