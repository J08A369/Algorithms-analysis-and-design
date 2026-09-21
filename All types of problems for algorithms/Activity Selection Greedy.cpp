#include <iostream>
#include <algorithm>
using namespace std;

struct Activity {
    int start, finish;
};

bool compare(Activity a, Activity b) {
    return a.finish < b.finish;
}

int main() {
    Activity a[] = {
        {1, 2}, {3, 4}, {0, 6},
        {5, 7}, {8, 9}, {5, 9}
    };

    int n = 6;

    sort(a, a + n, compare);

    cout << "Selected Activities:\n";

    int lastFinish = a[0].finish;
    cout << "(" << a[0].start << ", " << a[0].finish << ")\n";

    for (int i = 1; i < n; i++) {
        if (a[i].start >= lastFinish) {
            cout << "(" << a[i].start << ", "
                 << a[i].finish << ")\n";

            lastFinish = a[i].finish;
        }
    }

    return 0;
}
