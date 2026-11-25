#include <iostream>
using namespace std;

int main()
{
    int q[100], cap, choice, x, rear, i;

    cout << "Enter the capacity of the queue:" << endl;
    cin >> cap;

    if (cap < 1 || cap > 100)
    {
        cout << "Invalid capacity." << endl;
        return 0;
    }

    rear = 0;

    while (1)
    {
        cout << "1. Enqueue  2. Display  3. Exit" << endl;
        cout << "Enter choice:" << endl;
        cin >> choice;

        if (choice == 1)
        {
            if (rear == cap)
                cout << "Queue Overflow! Cannot enqueue more elements." << endl;
            else
            {
                cout << "Enter the element:" << endl;
                cin >> x;
                q[rear] = x;
                rear = rear + 1;
                cout << x << " enqueued successfully." << endl;
            }
        }
        else if (choice == 2)
        {
            if (rear == 0)
                cout << "Queue is empty." << endl;
            else
            {
                cout << "Queue: ";
                for (i = 0; i < rear; i++)
                    cout << q[i] << " ";
                cout << endl;
            }
        }
        else if (choice == 3)
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
