#include <iostream>
using namespace std;

#define V 4
#define INF 9999

int graph[V][V] = {
    {0, 10, 15, 20},
    {10, 0, 35, 25},
    {15, 35, 0, 30},
    {20, 25, 30, 0}
};

int dp[1 << V][V];

int tsp(int mask, int pos) {

    if (mask == (1 << V) - 1)
        return graph[pos][0];

    if (dp[mask][pos] != -1)
        return dp[mask][pos];

    int answer = INF;

    for (int city = 0; city < V; city++) {

        if (!(mask & (1 << city))) {

            answer = min(
                answer,
                graph[pos][city] +
                tsp(mask | (1 << city), city)
            );
        }
    }

    return dp[mask][pos] = answer;
}

int main() {

    for (int i = 0; i < (1 << V); i++)
        for (int j = 0; j < V; j++)
            dp[i][j] = -1;

    cout << "Minimum TSP Cost = "
         << tsp(1, 0);

    return 0;
}
