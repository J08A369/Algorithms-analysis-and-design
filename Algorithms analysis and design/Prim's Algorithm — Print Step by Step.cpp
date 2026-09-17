#include <iostream>
using namespace std;

int main() {

    int g[5][5] = {
        {0, 5, 3, 0, 0},
        {5, 0, 4, 6, 0},
        {3, 4, 0, 2, 7},
        {0, 6, 2, 0, 1},
        {0, 0, 7, 1, 0}
    };

    int key[5] = {0, 999, 999, 999, 999};
    int parent[5];
    bool used[5] = {false};

    parent[0] = -1;

    cout << "Prim's Algorithm Steps:\n";

    for (int count = 0; count < 4; count++) {

        int u = -1;

        for (int i = 0; i < 5; i++) {
            if (!used[i] &&
                (u == -1 || key[i] < key[u]))
                u = i;
        }

        used[u] = true;

        if (parent[u] != -1) {
            cout << "Step " << count + 1 << ": "
                 << parent[u] << " - "
                 << u << " = "
                 << key[u] << endl;
        }

        for (int v = 0; v < 5; v++) {
            if (g[u][v] != 0 &&
                !used[v] &&
                g[u][v] < key[v]) {

                key[v] = g[u][v];
                parent[v] = u;
            }
        }
    }

    return 0;
}
