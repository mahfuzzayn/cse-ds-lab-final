#include <iostream>
using namespace std;

int main()
{
    int st[100], n, x, i, top, sum;

    cout << "Enter the number of elements:" << endl;
    cin >> n;

    top = -1;

    cout << "Enter " << n << " elements:" << endl;
    for (i = 0; i < n; i++)
    {
        cin >> x;
        top = top + 1;
        st[top] = x;
    }

    if (top == -1)
    {
        cout << "Stack is empty." << endl;
        return 0;
    }

    sum = 0;
    for (i = 0; i <= top; i++)
        sum = sum + st[i];

    cout << "Sum of stack elements = " << sum << endl;

    return 0;
}
