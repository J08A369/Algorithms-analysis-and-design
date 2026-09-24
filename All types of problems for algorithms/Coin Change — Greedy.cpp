#include <iostream>
using namespace std;

int main() {

    int coins[] = {25, 10, 5, 1};
    int n = 4;

    int amount = 63;

    cout << "Coins used: ";

    for (int i = 0; i < n; i++) {

        while (amount >= coins[i]) {
            cout << coins[i] << " ";
            amount -= coins[i];
        }
    }

    return 0;
}
