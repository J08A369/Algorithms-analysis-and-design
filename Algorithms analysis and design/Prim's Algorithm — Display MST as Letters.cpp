#include <iostream>
using namespace std;

int main() {

    int g[5][5] = {
        {0, 6, 1, 5, 0},
        {6, 0, 5, 2, 5},
        {1, 5, 0, 4, 5},
        {5, 2, 4, 0, 3},
        {0, 5, 5, 3, 0}
    };

    int key[5] = {0, 999, 999, 999, 999};
    int parent[5];
    bool used[5] = {false};

    parent[0] = -1;

    for (int c = 0; c < 4; c++) {

        int u = -1;

        for (int i = 0; i < 5; i++) {
            if (!used[i] &&
                (u == -1 || key[i] < key[u]))
                u = i;
        }

        used[u] = true;

        for (int v = 0; v < 5; v++) {
            if (g[u][v] &&
                !used[v] &&
                g[u][v] < key[v]) {

                key[v] = g[u][v];
                parent[v] = u;
            }
        }
    }

    int total = 0;

    cout << "Minimum Spanning Tree:\n";

    for (int i = 1; i < 5; i++) {

        cout << char('A' + parent[i])
             << " --- "
             << char('A' + i)
             << " : "
             << key[i] << endl;

        total += key[i];
    }

    cout << "\nMinimum Cost = " << total << endl;

    return 0;
}
