#include <iostream>
using namespace std;

int main()
{
    int a[100], b[100], n, x, pos, i;

    cout << "How many elements?" << endl;
    cin >> n;

    cout << "Enter " << n << " elements:" << endl;
    for (i = 0; i < n; i++)
        cin >> a[i];

    cout << "Enter the value to insert:" << endl;
    cin >> x;

    cout << "Enter the position:" << endl;
    cin >> pos;

    if (pos < 1 || pos > n + 1)
    {
        cout << "Invalid position!" << endl;
        return 0;
    }

    for (i = 0; i < pos - 1; i++)
        b[i] = a[i];

    b[pos - 1] = x;

    for (i = pos - 1; i < n; i++)
        b[i + 1] = a[i];

    cout << "New array: ";
    for (i = 0; i <= n; i++)
        cout << b[i] << " ";
    cout << endl;

    return 0;
}
