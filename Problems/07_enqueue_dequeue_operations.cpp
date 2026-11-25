#include <iostream>
using namespace std;

int main()
{
    int q[100], cap, choice, x, front, rear, i;

    cout << "Enter the capacity of the queue:" << endl;
    cin >> cap;

    if (cap < 1 || cap > 100)
    {
        cout << "Invalid capacity." << endl;
        return 0;
    }

    front = 0;
    rear = -1;

    while (1)
    {
        cout << "1. Enqueue  2. Dequeue  3. Display  4. Exit" << endl;
        cout << "Enter choice:" << endl;
        cin >> choice;

        if (choice == 1)
        {
            if (rear == cap - 1)
                cout << "Queue Overflow!" << endl;
            else
            {
                cout << "Enter the element:" << endl;
                cin >> x;
                rear = rear + 1;
                q[rear] = x;
                cout << x << " enqueued." << endl;
            }
        }
        else if (choice == 2)
        {
            if (front > rear)
                cout << "Queue Underflow!" << endl;
            else
            {
                cout << q[front] << " dequeued." << endl;
                front = front + 1;
            }
        }
        else if (choice == 3)
        {
            if (front > rear)
                cout << "Queue is empty." << endl;
            else
            {
                cout << "Queue: ";
                for (i = front; i <= rear; i++)
                    cout << q[i] << " ";
                cout << endl;
            }
        }
        else if (choice == 4)
        {
            break;
        }
        else
        {
            cout << "Invalid choice." << endl;
        }
    }

    return 0;
}
