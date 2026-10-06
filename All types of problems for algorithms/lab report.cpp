#include <iostream>
using namespace std;

#define V 5
#define INF 9999

int main() {

    // Graph representation
    int graph[V][V] = {
        {0, 7, 3, 12, 9},
        {7, 0, 0, 0, 9},
        {3, 0, 0, 0, 7},
        {12, 0, 0, 0, 5},
        {9, 9, 7, 5, 0}
    };

    int key[V];
    int parent[V];
    bool visited[V];

    // Initialize arrays
    for (int i = 0; i < V; i++) {
        key[i] = INF;
        visited[i] = false;
    }

    // Start from vertex A
    key[0] = 0;
    parent[0] = -1;

    // Prim's Algorithm
    for (int count = 0; count < V - 1; count++) {

        int u = -1;

        // Find the vertex with minimum key value
        for (int i = 0; i < V; i++) {

            if (!visited[i] &&
                (u == -1 || key[i] < key[u])) {
                u = i;
            }
        }

        visited[u] = true;

        // Update key values of adjacent vertices
        for (int v = 0; v < V; v++) {

            if (graph[u][v] != 0 &&
                !visited[v] &&
                graph[u][v] < key[v]) {

                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    // Display Minimum Spanning Tree
    cout << "Minimum Spanning Tree:\n";

    int totalCost = 0;

    for (int i = 1; i < V; i++) {

        cout << char('A' + parent[i])
             << " - "
             << char('A' + i)
             << " = "
             << key[i]
             << endl;

        totalCost += key[i];
    }

    cout << "\nTotal Cost = " << totalCost << endl;

    return 0;
}
