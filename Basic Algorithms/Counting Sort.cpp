#include <iostream>
using namespace std;

int main()
{
    int arr[5] = {4, 2, 2, 8, 3};
    int count[9] = {0};

    for(int i = 0; i < 5; i++)
    {
        count[arr[i]]++;
    }

    cout << "Sorted Array: ";

    for(int i = 0; i < 9; i++)
    {
        while(count[i] > 0)
        {
            cout << i << " ";
            count[i]--;
        }
    }

    return 0;
}
