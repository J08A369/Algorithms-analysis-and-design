#include <iostream>
using namespace std;

int main() {

    int graph[5][5] = {
        {0, 2, 3, 6, 0},
        {2, 0, 1, 8, 5},
        {3, 1, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    int key[5] = {999, 0, 999, 999, 999};
    int parent[5];
    bool visited[5] = {false};

    parent[1] = -1;

    for (int count = 0; count < 4; count++) {

        int u = -1;

        for (int i = 0; i < 5; i++) {
            if (!visited[i] &&
                (u == -1 || key[i] < key[u]))
                u = i;
        }

        visited[u] = true;

        for (int v = 0; v < 5; v++) {
            if (graph[u][v] &&
                !visited[v] &&
                graph[u][v] < key[v]) {

                key[v] = graph[u][v];
                parent[v] = u;
            }
        }
    }

    int total = 0;

    cout << "MST Starting from B:\n";

    for (int i = 0; i < 5; i++) {
        if (i != 1) {
            cout << parent[i] << " - "
                 << i << " = "
                 << key[i] << endl;

            total += key[i];
        }
    }

    cout << "Total Cost = " << total << endl;

    return 0;
}
