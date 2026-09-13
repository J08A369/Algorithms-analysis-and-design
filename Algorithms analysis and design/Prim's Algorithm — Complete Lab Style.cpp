#include <iostream>
using namespace std;

int main() {

    int n = 5;

    int graph[5][5] = {
        {0, 10, 6, 5, 0},
        {10, 0, 0, 15, 4},
        {6, 0, 0, 4, 0},
        {5, 15, 4, 0, 3},
        {0, 4, 0, 3, 0}
    };

    int key[5];
    int parent[5];
    bool mst[5] = {false};

    for (int i = 0; i < n; i++) {
        key[i] = 999;
        parent[i] = -1;
    }

    key[0] = 0;

    for (int count = 0; count < n; count++) {

        int u = -1;

        for (int i = 0; i < n; i++) {

            if (!mst[i] &&
                (u == -1 || key[i] < key[u])) {

                u = i;
            }
        }

        mst[u] = true;

        for (int v = 0; v < n; v++) {

            if (graph[u][v] != 0 &&
                !mst[v] &&
                graph[u][v] < key[v]) {

                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    int total = 0;

    cout << "===== PRIM'S ALGORITHM =====\n";
    cout << "Minimum Spanning Tree:\n";

    for (int i = 1; i < n; i++) {

        cout << char('A' + parent[i])
             << " -> "
             << char('A' + i)
             << "  Weight = "
             << key[i] << endl;

        total += key[i];
    }

    cout << "----------------------------\n";
    cout << "Minimum Cost = " << total << endl;

    return 0;
}
