#include <iostream>
using namespace std;

int main()
{
    int st[100], n, x, i, top, sum;
    double avg;

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

    avg = (double)sum / (top + 1);

    cout << "Sum of stack elements = " << sum << endl;
    cout << "Average of stack elements = " << avg << endl;

    return 0;
}
