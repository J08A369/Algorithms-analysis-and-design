#include <iostream>
#include <algorithm>
using namespace std;

struct Job {
    char id;
    int deadline;
    int profit;
};

bool compare(Job a, Job b) {
    return a.profit > b.profit;
}

int main() {

    Job jobs[] = {
        {'A', 2, 100},
        {'B', 1, 19},
        {'C', 2, 27},
        {'D', 1, 25},
        {'E', 3, 15}
    };

    int n = 5;

    sort(jobs, jobs + n, compare);

    int slot[4] = {-1, -1, -1, -1};
    int totalProfit = 0;

    for (int i = 0; i < n; i++) {

        for (int j = jobs[i].deadline; j > 0; j--) {

            if (slot[j] == -1) {
                slot[j] = i;
                totalProfit += jobs[i].profit;
                break;
            }
        }
    }

    cout << "Selected Jobs: ";

    for (int i = 1; i <= 3; i++) {
        if (slot[i] != -1)
            cout << jobs[slot[i]].id << " ";
    }

    cout << "\nTotal Profit = " << totalProfit;

    return 0;
}
