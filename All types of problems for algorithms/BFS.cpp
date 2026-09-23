#include <iostream>
#include <queue>
using namespace std;

int main() {

    int graph[5][5] = {
        {0,1,1,0,0},
        {1,0,0,1,0},
        {1,0,0,0,1},
        {0,1,0,0,1},
        {0,0,1,1,0}
    };

    bool visited[5] = {false};

    queue<int> q;

    q.push(0);
    visited[0] = true;

    cout << "BFS: ";

    while (!q.empty()) {

        int u = q.front();
        q.pop();

        cout << u << " ";

        for (int v = 0; v < 5; v++) {

            if (graph[u][v] && !visited[v]) {

                visited[v] = true;
                q.push(v);
            }
        }
    }

    return 0;
}
