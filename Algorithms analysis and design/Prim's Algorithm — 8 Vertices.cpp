#include <iostream>
using namespace std;

int main() {

    const int n = 8;

    int g[n][n] = {
        {0,4,3,0,0,0,0,0},
        {4,0,2,5,0,0,0,0},
        {3,2,0,3,4,0,0,0},
        {0,5,3,0,2,6,0,0},
        {0,0,4,2,0,1,5,0},
        {0,0,0,6,1,0,2,4},
        {0,0,0,0,5,2,0,3},
        {0,0,0,0,0,4,3,0}
    };

    int key[n], parent[n];
    bool used[n] = {false};

    for (int i = 0; i < n; i++)
        key[i] = 999;

    key[0] = 0;
    parent[0] = -1;

    for (int c = 0; c < n - 1; c++) {

        int u = -1;

        for (int i = 0; i < n; i++)
            if (!used[i] &&
                (u == -1 || key[i] < key[u]))
                u = i;

        used[u] = true;

        for (int v = 0; v < n; v++)
            if (g[u][v] &&
                !used[v] &&
                g[u][v] < key[v]) {

                key[v] = g[u][v];
                parent[v] = u;
            }
    }

    int total = 0;

    for (int i = 1; i < n; i++) {
        cout << parent[i] << " - "
             << i << " = "
             << key[i] << endl;
        total += key[i];
    }

    cout << "Total = " << total << endl;

    return 0;
}
