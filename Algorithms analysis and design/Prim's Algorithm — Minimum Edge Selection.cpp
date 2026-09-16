#include <iostream>
using namespace std;

int main() {

    int g[5][5] = {
        {0,8,3,7,0},
        {8,0,2,0,6},
        {3,2,0,4,5},
        {7,0,4,0,1},
        {0,6,5,1,0}
    };

    bool inside[5] = {true, false, false, false, false};

    int total = 0;

    cout << "Selected Edges:\n";

    for (int step = 0; step < 4; step++) {

        int minWeight = 999;
        int from = -1;
        int to = -1;

        for (int i = 0; i < 5; i++) {

            if (inside[i]) {

                for (int j = 0; j < 5; j++) {

                    if (!inside[j] &&
                        g[i][j] != 0 &&
                        g[i][j] < minWeight) {

                        minWeight = g[i][j];
                        from = i;
                        to = j;
                    }
                }
            }
        }

        inside[to] = true;

        cout << from << " - "
             << to << " = "
             << minWeight << endl;

        total += minWeight;
    }

    cout << "Total Cost = " << total << endl;

    return 0;
}
