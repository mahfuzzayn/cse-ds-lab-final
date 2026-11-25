#include <iostream>
using namespace std;

int main()
{
    int a[100], q1[100], q2[100], n, i, r1, r2;

    cout << "Enter the size of the array:" << endl;
    cin >> n;

    cout << "Enter " << n << " elements:" << endl;
    for (i = 0; i < n; i++)
        cin >> a[i];

    r1 = 0;
    r2 = 0;

    for (i = 0; i < n; i++)
    {
        if (a[i] % 2 == 0)
        {
            q1[r1] = a[i];
            r1 = r1 + 1;
        }
        else
        {
            q2[r2] = a[i];
            r2 = r2 + 1;
        }
    }

    if (r1 == 0)
        cout << "Even queue is empty." << endl;
    else
    {
        cout << "Even queue: ";
        for (i = 0; i < r1; i++)
            cout << q1[i] << " ";
        cout << endl;
    }

    if (r2 == 0)
        cout << "Odd queue is empty." << endl;
    else
    {
        cout << "Odd queue: ";
        for (i = 0; i < r2; i++)
            cout << q2[i] << " ";
        cout << endl;
    }

    return 0;
}
