#include <iostream>
using namespace std;

int main()
{
    int s1[100], s2[100], temp[100], n, x, i;
    int top1 = -1, top2 = -1, topt = -1;

    cout << "Enter the number of elements:" << endl;
    cin >> n;

    cout << "Enter " << n << " elements:" << endl;
    for (i = 0; i < n; i++)
    {
        cin >> x;
        top1 = top1 + 1;
        s1[top1] = x;
    }

    while (top1 != -1)
    {
        topt = topt + 1;
        temp[topt] = s1[top1];
        top1 = top1 - 1;
    }

    while (topt != -1)
    {
        x = temp[topt];
        topt = topt - 1;
        top1 = top1 + 1;
        s1[top1] = x;
        top2 = top2 + 1;
        s2[top2] = x;
    }

    cout << "Stack 1 (top to bottom): ";
    for (i = top1; i >= 0; i--)
        cout << s1[i] << " ";
    cout << endl;

    cout << "Stack 2 (top to bottom): ";
    for (i = top2; i >= 0; i--)
        cout << s2[i] << " ";
    cout << endl;

    return 0;
}
