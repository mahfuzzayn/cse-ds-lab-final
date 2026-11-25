#include <iostream>
using namespace std;

int a[100], b[100];

void mergeArray(int low, int mid, int high)
{
    int i = low, j = mid + 1, k = low;

    while (i <= mid && j <= high)
    {
        if (a[i] <= a[j])
        {
            b[k] = a[i];
            i = i + 1;
        }
        else
        {
            b[k] = a[j];
            j = j + 1;
        }
        k = k + 1;
    }

    while (i <= mid)
    {
        b[k] = a[i];
        i = i + 1;
        k = k + 1;
    }

    while (j <= high)
    {
        b[k] = a[j];
        j = j + 1;
        k = k + 1;
    }

    for (i = low; i <= high; i++)
        a[i] = b[i];
}

void mergeSort(int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        mergeSort(low, mid);
        mergeSort(mid + 1, high);
        mergeArray(low, mid, high);
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

    mergeSort(0, n - 1);

    cout << "Array after merge sort: ";
    for (i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;

    return 0;
}
