#include <iostream>
#include <queue>
using namespace std;

int main() {

    int V = 6;

    int graph[6][6] = {
        {0,1,1,0,0,0},
        {0,0,0,1,0,0},
        {0,0,0,1,1,0},
        {0,0,0,0,0,1},
        {0,0,0,0,0,1},
        {0,0,0,0,0,0}
    };

    int indegree[6] = {0};

    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            if (graph[i][j])
                indegree[j]++;

    queue<int> q;

    for (int i = 0; i < V; i++)
        if (indegree[i] == 0)
            q.push(i);

    cout << "Topological Order: ";

    while (!q.empty()) {

        int u = q.front();
        q.pop();

        cout << u << " ";

        for (int v = 0; v < V; v++) {

            if (graph[u][v]) {

                indegree[v]--;

                if (indegree[v] == 0)
                    q.push(v);
            }
        }
    }

    return 0;
}
