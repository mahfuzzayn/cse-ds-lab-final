#include <iostream>
using namespace std;

int main()
{
    int a[100], n, x, pos, i;

    cout << "Enter the size of the array:" << endl;
    cin >> n;

    cout << "Enter " << n << " elements:" << endl;
    for (i = 0; i < n; i++)
        cin >> a[i];

    cout << "Enter the element to insert:" << endl;
    cin >> x;

    cout << "Enter the position (1 to " << n + 1 << "):" << endl;
    cin >> pos;

    if (pos < 1 || pos > n + 1)
    {
        cout << "Invalid position!" << endl;
        return 0;
    }

    for (i = n; i >= pos; i--)
        a[i] = a[i - 1];

    a[pos - 1] = x;
    n = n + 1;

    cout << "Array after insertion: ";
    for (i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;

    return 0;
}
