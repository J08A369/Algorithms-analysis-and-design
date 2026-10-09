#include <iostream>
using namespace std;

int main() {

    int arr[] = {10, 22, 9, 33, 21, 50, 41, 60};

    int n = 8;
    int dp[8];

    for (int i = 0; i < n; i++)
        dp[i] = 1;

    for (int i = 1; i < n; i++) {

        for (int j = 0; j < i; j++) {

            if (arr[i] > arr[j])
                dp[i] = max(dp[i],
                            dp[j] + 1);
        }
    }

    int answer = 0;

    for (int i = 0; i < n; i++)
        answer = max(answer, dp[i]);

    cout << "LIS Length = " << answer;

    return 0;
}
