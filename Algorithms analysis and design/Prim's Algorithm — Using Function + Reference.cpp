#include <iostream>
using namespace std;

void prim(int g[][5], int n) {

    int key[5] = {0,999,999,999,999};
    int parent[5];
    bool used[5] = {false};

    parent[0] = -1;

    for (int c = 0; c < n - 1; c++) {

        int u = -1;

        for (int i = 0; i < n; i++) {
            if (!used[i] &&
                (u == -1 || key[i] < key[u]))
                u = i;
        }

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

    cout << "MST:\n";

    for (int i = 1; i < n; i++) {
        cout << parent[i] << " - "
             << i << " = "
             << key[i] << endl;
        total += key[i];
    }

    cout << "Cost = " << total << endl;
}

int main() {

    int graph[5][5] = {
        {0,9,4,0,0},
        {9,0,6,2,0},
        {4,6,0,5,3},
        {0,2,5,0,7},
        {0,0,3,7,0}
    };

    prim(graph, 5);

    return 0;
}
