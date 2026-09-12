#include <iostream>
using namespace std;

int main() {

    int g[4][4] = {
        {0, 10, 6, 5},
        {10, 0, 15, 4},
        {6, 15, 0, 8},
        {5, 4, 8, 0}
    };

    int key[4] = {0, 999, 999, 999};
    int parent[4];
    bool used[4] = {false};

    parent[0] = -1;

    for (int c = 0; c < 3; c++) {

        int u = -1;

        for (int i = 0; i < 4; i++)
            if (!used[i] &&
                (u == -1 || key[i] < key[u]))
                u = i;

        used[u] = true;

        for (int v = 0; v < 4; v++)
            if (g[u][v] &&
                !used[v] &&
                g[u][v] < key[v]) {

                key[v] = g[u][v];
                parent[v] = u;
            }
    }

    int total = 0;

    for (int i = 1; i < 4; i++) {
        cout << parent[i] << " - "
             << i << " = "
             << key[i] << endl;

        total += key[i];
    }

    cout << "MST Cost = " << total << endl;

    return 0;
}
