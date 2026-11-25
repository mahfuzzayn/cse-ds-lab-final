#include <iostream>
using namespace std;

int main()
{
    int q[100], n, x, i, found;

    cout << "Enter the size of the queue:" << endl;
    cin >> n;

    cout << "Enter " << n << " elements:" << endl;
    for (i = 0; i < n; i++)
        cin >> q[i];

    cout << "Enter the element to search:" << endl;
    cin >> x;

    found = 0;
    for (i = 0; i < n; i++)
    {
        if (q[i] == x)
        {
            cout << x << " found at position " << i + 1 << " from the front of the queue." << endl;
            found = 1;
            break;
        }
    }

    if (found == 0)
        cout << x << " is not present in the queue." << endl;

    return 0;
}
