#include <iostream>
using namespace std;

int main()
{
    int a[100], n, i, j, m, temp;

    cout << "Enter the size of the array:" << endl;
    cin >> n;

    cout << "Enter " << n << " elements:" << endl;
    for (i = 0; i < n; i++)
        cin >> a[i];

    for (i = 0; i < n - 1; i++)
    {
        m = i;
        for (j = i + 1; j < n; j++)
        {
            if (a[j] < a[m])
                m = j;
        }
        if (m != i)
        {
            temp = a[i];
            a[i] = a[m];
            a[m] = temp;
        }
    }

    cout << "Array after selection sort: ";
    for (i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;

    return 0;
}
