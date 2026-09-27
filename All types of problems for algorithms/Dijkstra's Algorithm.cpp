#include <iostream>
using namespace std;

#define V 5

int main() {

    int graph[V][V] = {
        {0, 10, 0, 5, 0},
        {0, 0, 1, 2, 0},
        {0, 0, 0, 0, 4},
        {0, 3, 9, 0, 2},
        {7, 0, 6, 0, 0}
    };

    int dist[V];
    bool visited[V];

    for (int i = 0; i < V; i++) {
        dist[i] = 9999;
        visited[i] = false;
    }

    dist[0] = 0;

    for (int count = 0; count < V - 1; count++) {

        int u = -1;

        for (int i = 0; i < V; i++) {
            if (!visited[i] &&
                (u == -1 || dist[i] < dist[u]))
                u = i;
        }

        visited[u] = true;

        for (int v = 0; v < V; v++) {

            if (graph[u][v] &&
                dist[u] + graph[u][v] < dist[v]) {

                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    for (int i = 0; i < V; i++)
        cout << "0 -> " << i
             << " = " << dist[i] << endl;

    return 0;
}
