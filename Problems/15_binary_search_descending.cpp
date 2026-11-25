#include <iostream>
using namespace std;

int main()
{
    int a[100], n, x, i, low, high, mid, pos;

    cout << "Enter the size of the array:" << endl;
    cin >> n;

    cout << "Enter " << n << " elements in descending order:" << endl;
    for (i = 0; i < n; i++)
        cin >> a[i];

    cout << "Enter the element to search:" << endl;
    cin >> x;

    low = 0;
    high = n - 1;
    pos = -1;

    while (low <= high)
    {
        mid = (low + high) / 2;
        if (a[mid] == x)
        {
            pos = mid;
            break;
        }
        else if (a[mid] > x)
            low = mid + 1;
        else
            high = mid - 1;
    }

    if (pos == -1)
        cout << x << " is not found in the array." << endl;
    else
        cout << x << " is found at position " << pos + 1 << "." << endl;

    return 0;
}
