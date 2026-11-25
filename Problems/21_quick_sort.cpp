#include <iostream>
using namespace std;

int a[100];

int partition(int low, int high)
{
    int pivot = a[high];
    int i = low - 1;
    int j, temp;

    for (j = low; j < high; j++)
    {
        if (a[j] < pivot)
        {
            i = i + 1;
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }

    temp = a[i + 1];
    a[i + 1] = a[high];
    a[high] = temp;

    return i + 1;
}

void quickSort(int low, int high)
{
    if (low < high)
    {
        int p = partition(low, high);
        quickSort(low, p - 1);
        quickSort(p + 1, high);
    }
}

int main()
{
    int n, i;

    cout << "Enter the size of the array:" << endl;
    cin >> n;

    cout << "Enter " << n << " elements:" << endl;
    for (i = 0; i < n; i++)
        cin >> a[i];

    quickSort(0, n - 1);

    cout << "Array after quick sort: ";
    for (i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;

    return 0;
}
