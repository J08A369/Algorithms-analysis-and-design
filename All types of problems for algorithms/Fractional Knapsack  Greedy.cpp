#include <iostream>
#include <algorithm>
using namespace std;

struct Item {
    int weight;
    int value;
};

bool compare(Item a, Item b) {
    return (double)a.value / a.weight >
           (double)b.value / b.weight;
}

int main() {
    Item items[] = {
        {10, 60},
        {20, 100},
        {30, 120}
    };

    int n = 3;
    int capacity = 50;

    sort(items, items + n, compare);

    double profit = 0;

    for (int i = 0; i < n; i++) {

        if (capacity >= items[i].weight) {
            capacity -= items[i].weight;
            profit += items[i].value;
        }
        else {
            profit += (double)items[i].value
                    * capacity / items[i].weight;
            break;
        }
    }

    cout << "Maximum Profit = " << profit;

    return 0;
}
