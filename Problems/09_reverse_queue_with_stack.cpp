#include <iostream>
using namespace std;

int main()
{
    int q[100], st[100], n, i, front, rear, top;

    cout << "Enter the size of the queue:" << endl;
    cin >> n;

    cout << "Enter " << n << " elements:" << endl;
    for (i = 0; i < n; i++)
        cin >> q[i];

    front = 0;
    rear = n - 1;
    top = -1;

    cout << "Queue before reverse: ";
    for (i = front; i <= rear; i++)
        cout << q[i] << " ";
    cout << endl;

    while (front <= rear)
    {
        top = top + 1;
        st[top] = q[front];
        front = front + 1;
    }

    front = 0;
    rear = -1;

    while (top != -1)
    {
        rear = rear + 1;
        q[rear] = st[top];
        top = top - 1;
    }

    cout << "Queue after reverse: ";
    for (i = front; i <= rear; i++)
        cout << q[i] << " ";
    cout << endl;

    return 0;
}
