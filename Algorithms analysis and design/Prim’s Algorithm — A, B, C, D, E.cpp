#include <iostream>
using namespace std;

#define V 5
#define INF 9999

int main() {

    int graph[V][V] = {
        {0, 7, 3, 12, 9},
        {7, 0, 0, 0, 9},
        {3, 0, 0, 0, 7},
        {12, 0, 0, 0, 5},
        {9, 9, 7, 5, 0}
    };

    int key[V], parent[V];
    bool visited[V] = {false};

    for (int i = 0; i < V; i++)
        key[i] = INF;

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < V - 1; count++) {

        int u = -1;

        for (int i = 0; i < V; i++) {
            if (!visited[i] &&
                (u == -1 || key[i] < key[u]))
                u = i;
        }

        visited[u] = true;

        for (int v = 0; v < V; v++) {
            if (graph[u][v] != 0 &&
                !visited[v] &&
                graph[u][v] < key[v]) {

                key[v] = graph[u][v];
                parent[v] = u;
            }
        }
    }

    int total = 0;

    for (int i = 1; i < V; i++) {
        cout << char('A' + parent[i])
             << " - "
             << char('A' + i)
             << " = " << key[i] << endl;

        total += key[i];
    }

    cout << "Total Cost = " << total << endl;

    return 0;
}
