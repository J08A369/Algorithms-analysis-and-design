#include <iostream>
using namespace std;

#define V 4
#define INF 9999

int main() {

    int graph[V][V] = {
        {0, 2, 3, 0},
        {2, 0, 1, 4},
        {3, 1, 0, 5},
        {0, 4, 5, 0}
    };

    int key[V] = {0, INF, INF, INF};
    bool visited[V] = {false};

    int total = 0;

    for (int count = 0; count < V; count++) {

        int u = -1;

        for (int i = 0; i < V; i++) {
            if (!visited[i] &&
                (u == -1 || key[i] < key[u]))
                u = i;
        }

        visited[u] = true;
        total += key[u];

        for (int v = 0; v < V; v++) {
            if (graph[u][v] != 0 &&
                !visited[v] &&
                graph[u][v] < key[v])
                key[v] = graph[u][v];
        }
    }

    cout << "Minimum Cost = " << total << endl;

    return 0;
}
