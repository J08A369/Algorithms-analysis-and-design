#include <iostream>
using namespace std;

int main()
{
    int arr[5] = {10, 20, 30, 40, 50};

    int search = 40;
    int low = 0, high = 4;
    int mid, found = 0;

    while(low <= high)
    {
        mid = (low + high) / 2;

        if(arr[mid] == search)
        {
            cout << "Element Found at Position " << mid + 1;
            found = 1;
            break;
        }
        else if(arr[mid] < search)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    if(found == 0)
        cout << "Element Not Found";

    return 0;
}
