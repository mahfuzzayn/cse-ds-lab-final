#include <iostream>
using namespace std;

int main()
{
    int a[100], n, i, j, key;

    cout << "Enter the size of the array:" << endl;
    cin >> n;

    cout << "Enter " << n << " elements:" << endl;
    for (i = 0; i < n; i++)
        cin >> a[i];

    for (i = 1; i < n; i++)
    {
        key = a[i];
        if (key % 2 == 0)
        {
            j = i - 1;
            while (j >= 0 && a[j] % 2 != 0)
            {
                a[j + 1] = a[j];
                j = j - 1;
            }
            a[j + 1] = key;
        }
    }

    cout << "Array after arranging: ";
    for (i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;

    return 0;
}
