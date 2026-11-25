#include <iostream>
using namespace std;

int main()
{
    int a[100], b[100], n, i, j, temp, count;

    cout << "Enter the size of the array:" << endl;
    cin >> n;

    cout << "Enter " << n << " elements:" << endl;
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
        b[i] = a[i];
    }

    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - 1 - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }

    cout << "Sorted array: ";
    for (i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;

    cout << "Elements that changed position: ";
    count = 0;
    for (i = 0; i < n; i++)
    {
        if (b[i] != a[i])
        {
            cout << b[i] << " ";
            count = count + 1;
        }
    }
    if (count == 0)
        cout << "None";
    cout << endl;

    return 0;
}
