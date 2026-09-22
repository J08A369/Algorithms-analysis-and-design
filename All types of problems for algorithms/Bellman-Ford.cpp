#include <iostream>
using namespace std;

struct Edge {
    int u, v, weight;
};

int main() {

    Edge edges[] = {
        {0, 1, 4},
        {0, 2, 5},
        {1, 2, -3},
        {2, 3, 4}
    };

    int V = 4;
    int E = 4;

    int dist[4];

    for (int i = 0; i < V; i++)
        dist[i] = 9999;

    dist[0] = 0;

    for (int i = 1; i <= V - 1; i++) {

        for (int j = 0; j < E; j++) {

            int u = edges[j].u;
            int v = edges[j].v;
            int w = edges[j].weight;

            if (dist[u] != 9999 &&
                dist[u] + w < dist[v]) {

                dist[v] = dist[u] + w;
            }
        }
    }

    for (int i = 0; i < V; i++)
        cout << "0 -> " << i
             << " = " << dist[i] << endl;

    return 0;
}
