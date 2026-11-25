#include <iostream>
using namespace std;

int main()
{
    int a[100], n, x, i, pos;

    cout << "Enter the size of the array:" << endl;
    cin >> n;

    cout << "Enter " << n << " elements:" << endl;
    for (i = 0; i < n; i++)
        cin >> a[i];

    cout << "Enter the element to search:" << endl;
    cin >> x;

    pos = -1;
    for (i = 0; i < n; i++)
    {
        if (a[i] == x)
        {
            pos = i;
            break;
        }
    }

    if (pos == -1)
        cout << x << " is not found in the array." << endl;
    else
        cout << x << " is found at position " << pos + 1 << "." << endl;

    return 0;
}
