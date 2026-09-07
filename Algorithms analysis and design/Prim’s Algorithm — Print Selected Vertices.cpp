#include <iostream>
using namespace std;

int main() {

    int graph[5][5] = {
        {0, 4, 2, 0, 0},
        {4, 0, 1, 5, 0},
        {2, 1, 0, 8, 10},
        {0, 5, 8, 0, 2},
        {0, 0, 10, 2, 0}
    };

    int key[5] = {0, 999, 999, 999, 999};
    bool visited[5] = {false};

    cout << "Selected Vertices: ";

    for (int count = 0; count < 5; count++) {

        int u = -1;

        for (int i = 0; i < 5; i++) {
            if (!visited[i] &&
                (u == -1 || key[i] < key[u]))
                u = i;
        }

        visited[u] = true;

        cout << u << " ";

        for (int v = 0; v < 5; v++) {
            if (graph[u][v] != 0 &&
                !visited[v] &&
                graph[u][v] < key[v])
                key[v] = graph[u][v];
        }
    }

    return 0;
}
