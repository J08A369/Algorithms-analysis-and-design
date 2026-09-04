#include <iostream>
using namespace std;

#define V 7
#define INF 9999

int main() {

    int graph[V][V] = {
        {0,2,0,6,0,0,0},
        {2,0,3,8,5,0,0},
        {0,3,0,0,7,0,0},
        {6,8,0,0,9,0,0},
        {0,5,7,9,0,1,2},
        {0,0,0,0,1,0,4},
        {0,0,0,0,2,4,0}
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

            if (graph[u][v] &&
                !visited[v] &&
                graph[u][v] < key[v]) {

                key[v] = graph[u][v];
                parent[v] = u;
            }
        }
    }

    int total = 0;

    cout << "MST:\n";

    for (int i = 1; i < V; i++) {
        cout << parent[i] << " - "
             << i << " = "
             << key[i] << endl;

        total += key[i];
    }

    cout << "Total Cost = " << total << endl;

    return 0;
}
