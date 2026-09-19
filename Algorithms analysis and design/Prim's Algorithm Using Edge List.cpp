#include <iostream>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, weight;
};

int main() {

    int n = 5;

    Edge edges[] = {
        {0, 1, 4},
        {0, 2, 8},
        {1, 2, 2},
        {1, 3, 6},
        {2, 3, 3},
        {2, 4, 5},
        {3, 4, 7}
    };

    int m = 7;
    bool selected[5] = {false};

    selected[0] = true;

    int total = 0;

    cout << "MST Edges:\n";

    for (int count = 0; count < n - 1; count++) {

        int best = -1;

        for (int i = 0; i < m; i++) {

            if (selected[edges[i].u] !=
                selected[edges[i].v]) {

                if (best == -1 ||
                    edges[i].weight < edges[best].weight) {
                    best = i;
                }
            }
        }

        selected[edges[best].u] = true;
        selected[edges[best].v] = true;

        cout << edges[best].u << " - "
             << edges[best].v << " = "
             << edges[best].weight << endl;

        total += edges[best].weight;
    }

    cout << "Total Cost = " << total << endl;

    return 0;
}
