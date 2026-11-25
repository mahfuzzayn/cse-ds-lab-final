#include <iostream>
using namespace std;

int main()
{
    int g[10][10], v, i, j, count;

    cout << "Enter the number of vertices:" << endl;
    cin >> v;

    if (v < 1 || v > 10)
    {
        cout << "Number of vertices must be between 1 and 10." << endl;
        return 0;
    }

    cout << "Enter the adjacency matrix:" << endl;
    for (i = 0; i < v; i++)
    {
        for (j = 0; j < v; j++)
            cin >> g[i][j];
    }

    count = 0;
    for (i = 0; i < v; i++)
    {
        for (j = i + 1; j < v; j++)
        {
            if (g[i][j] == 1)
                count = count + 1;
        }
    }

    cout << "Total number of edges = " << count << endl;

    return 0;
}
