#include <iostream>
using namespace std;

int main() {

    int n = 6;

    int g[6][6] = {
        {0,7,5,0,0,0},
        {7,0,3,6,0,0},
        {5,3,0,4,2,0},
        {0,6,4,0,5,3},
        {0,0,2,5,0,1},
        {0,0,0,3,1,0}
    };

    int key[6] = {0,999,999,999,999,999};
    int parent[6];
    bool used[6] = {false};

    parent[0] = -1;

    for (int c = 0; c < n - 1; c++) {

        int u = -1;

        for (int i = 0; i < n; i++)
            if (!used[i] &&
                (u == -1 || key[i] < key[u]))
                u = i;

        used[u] = true;

        for (int v = 0; v < n; v++) {
            if (g[u][v] &&
                !used[v] &&
                g[u][v] < key[v]) {

                key[v] = g[u][v];
                parent[v] = u;
            }
        }
    }

    int total = 0;

    for (int i = 1; i < n; i++)
        total += key[i];

    cout << "Number of MST Edges = " << n - 1 << endl;
    cout << "Total MST Cost = " << total << endl;

    return 0;
}
