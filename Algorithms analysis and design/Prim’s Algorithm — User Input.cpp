#include <iostream>
using namespace std;

#define MAX 20
#define INF 9999

int main() {

    int n;
    int graph[MAX][MAX];

    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter adjacency matrix:\n";

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> graph[i][j];

    int key[MAX], parent[MAX];
    bool visited[MAX] = {false};

    for (int i = 0; i < n; i++) {
        key[i] = INF;
        parent[i] = -1;
    }

    key[0] = 0;

    for (int count = 0; count < n - 1; count++) {

        int u = -1;

        for (int i = 0; i < n; i++) {
            if (!visited[i] &&
                (u == -1 || key[i] < key[u]))
                u = i;
        }

        visited[u] = true;

        for (int v = 0; v < n; v++) {
            if (graph[u][v] != 0 &&
                !visited[v] &&
                graph[u][v] < key[v]) {

                key[v] = graph[u][v];
                parent[v] = u;
            }
        }
    }

    int total = 0;

    cout << "MST:\n";

    for (int i = 1; i < n; i++) {
        cout << parent[i] << " - "
             << i << " = "
             << key[i] << endl;

        total += key[i];
    }

    cout << "Total Cost = " << total << endl;

    return 0;
}
