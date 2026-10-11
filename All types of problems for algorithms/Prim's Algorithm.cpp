#include <iostream>
using namespace std;

#define V 5

int main() {

    int graph[V][V] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    int key[V];
    bool selected[V];

    for (int i = 0; i < V; i++) {
        key[i] = 9999;
        selected[i] = false;
    }

    key[0] = 0;

    int parent[V];
    parent[0] = -1;

    for (int count = 0; count < V - 1; count++) {

        int u = -1;

        for (int i = 0; i < V; i++) {
            if (!selected[i] &&
                (u == -1 || key[i] < key[u]))
                u = i;
        }

        selected[u] = true;

        for (int v = 0; v < V; v++) {

            if (graph[u][v] &&
                !selected[v] &&
                graph[u][v] < key[v]) {

                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    cout << "Edges of MST:\n";

    for (int i = 1; i < V; i++) {
        cout << parent[i] << " - " << i
             << " = " << key[i] << endl;
    }

    return 0;
}
