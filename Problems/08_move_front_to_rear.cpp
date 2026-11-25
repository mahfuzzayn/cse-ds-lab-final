#include <iostream>
using namespace std;

int main()
{
    int q[100], n, i, temp;

    cout << "Enter the size of the queue:" << endl;
    cin >> n;

    if (n < 1)
    {
        cout << "Queue is empty." << endl;
        return 0;
    }

    cout << "Enter " << n << " elements:" << endl;
    for (i = 0; i < n; i++)
        cin >> q[i];

    temp = q[0];
    for (i = 0; i < n - 1; i++)
        q[i] = q[i + 1];
    q[n - 1] = temp;

    cout << "Queue after moving the first element to the rear: ";
    for (i = 0; i < n; i++)
        cout << q[i] << " ";
    cout << endl;

    return 0;
}
