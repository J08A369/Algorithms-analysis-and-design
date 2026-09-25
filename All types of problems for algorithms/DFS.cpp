#include <iostream>
using namespace std;

int graph[5][5] = {
    {0,1,1,0,0},
    {1,0,0,1,0},
    {1,0,0,0,1},
    {0,1,0,0,1},
    {0,0,1,1,0}
};

bool visited[5];

void DFS(int u) {

    visited[u] = true;

    cout << u << " ";

    for (int v = 0; v < 5; v++) {

        if (graph[u][v] && !visited[v])
            DFS(v);
    }
}

int main() {

    cout << "DFS: ";

    DFS(0);

    return 0;
}
