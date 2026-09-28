#include <iostream>
using namespace std;

int parent[10];

int find(int x) {

    if (parent[x] == x)
        return x;

    return parent[x] = find(parent[x]);
}

void unite(int a, int b) {

    a = find(a);
    b = find(b);

    if (a != b)
        parent[b] = a;
}

int main() {

    for (int i = 0; i < 5; i++)
        parent[i] = i;

    unite(0, 1);
    unite(1, 2);

    if (find(0) == find(2))
        cout << "Same Set";
    else
        cout << "Different Set";

    return 0;
}
