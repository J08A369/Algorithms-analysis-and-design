#include <iostream>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, weight;
};

bool compare(Edge a, Edge b) {
    return a.weight < b.weight;
}

int parent[10];

int find(int x) {
    if (parent[x] == x)
        return x;

    return parent[x] = find(parent[x]);
}

void unite(int a, int b) {
    parent[find(a)] = find(b);
}

int main() {

    Edge edges[] = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };

    int n = 5;

    for (int i = 0; i < 4; i++)
        parent[i] = i;

    sort(edges, edges + n, compare);

    cout << "MST Edges:\n";

    int count = 0;

    for (int i = 0; i < n && count < 3; i++) {

        int u = edges[i].u;
        int v = edges[i].v;

        if (find(u) != find(v)) {

            cout << u << " - " << v
                 << " = " << edges[i].weight << endl;

            unite(u, v);
            count++;
        }
    }

    return 0;
}
