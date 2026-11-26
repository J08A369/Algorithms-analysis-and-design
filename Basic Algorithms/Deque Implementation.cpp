#include <iostream>
using namespace std;

int main()
{
    int deque[5];
    int front = 2, rear = 2;

    deque[front] = 20;

    // Insert at Front
    front--;
    deque[front] = 10;

    // Insert at Rear
    rear++;
    deque[rear] = 30;

    cout << "Deque Elements: ";

    for(int i = front; i <= rear; i++)
    {
        cout << deque[i] << " ";
    }

    return 0;
}
