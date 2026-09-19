#include <iostream>
#include <vector>
using namespace std;

int main() {

    int n = 5;

    vector<vector<int>> graph = {
        {0, 9, 2, 0, 0},
        {9, 0, 6, 3, 0},
        {2, 6, 0, 4, 8},
        {0, 3, 4, 0, 5},
        {0, 0, 8, 5, 0}
    };

    vector<int> key(n, 999);
    vector<int> parent(n, -1);
    vector<bool> mst(n, false);

    key[0] = 0;

    for (int step = 0; step < n; step++) {

        int u = -1;

        for (int i = 0; i < n; i++) {
            if (!mst[i] && (u == -1 || key[i] < key[u]))
                u = i;
        }

        mst[u] = true;

        for (int v = 0; v < n; v++) {
            if (graph[u][v] != 0 &&
                !mst[v] &&
                graph[u][v] < key[v]) {

                key[v] = graph[u][v];
                parent[v] = u;
            }
        }
    }

    int total = 0;

    cout << "MST Edges:\n";

    for (int i = 1; i < n; i++) {
        cout << parent[i] << " - "
             << i << " = " << key[i] << endl;
        total += key[i];
    }

    cout << "Total Cost = " << total << endl;

    return 0;
}
