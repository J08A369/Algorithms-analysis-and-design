#include <iostream>
using namespace std;

int main()
{
    int queue[5];
    int front = -1, rear = -1;
    int n = 5;

    // Enqueue
    for(int i = 10; i <= 30; i += 10)
    {
        if(front == -1)
            front = 0;

        rear = (rear + 1) % n;
        queue[rear] = i;
    }

    cout << "Circular Queue: ";

    int i = front;

    while(true)
    {
        cout << queue[i] << " ";

        if(i == rear)
            break;

        i = (i + 1) % n;
    }

    // Dequeue
    cout << "\nDeleted Element: " << queue[front];
    front = (front + 1) % n;

    return 0;
}
