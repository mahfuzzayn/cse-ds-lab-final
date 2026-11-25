#include <iostream>
using namespace std;

int main()
{
    int a[100], n, x, i, low, high, mid, ans;

    cout << "Enter the size of the array:" << endl;
    cin >> n;

    cout << "Enter " << n << " elements in ascending order:" << endl;
    for (i = 0; i < n; i++)
        cin >> a[i];

    cout << "Enter the value:" << endl;
    cin >> x;

    low = 0;
    high = n - 1;
    ans = n;

    while (low <= high)
    {
        mid = (low + high) / 2;
        if (a[mid] < x)
            low = mid + 1;
        else
        {
            ans = mid;
            high = mid - 1;
        }
    }

    cout << "Number of elements smaller than " << x << " = " << ans << endl;

    return 0;
}
