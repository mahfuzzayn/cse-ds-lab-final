#include <iostream>
using namespace std;

int main()
{
    int g[10][10], v, e, u, w, i, j;

    cout << "Enter the number of vertices:" << endl;
    cin >> v;

    if (v < 1 || v > 10)
    {
        cout << "Number of vertices must be between 1 and 10." << endl;
        return 0;
    }

    cout << "Enter the number of edges:" << endl;
    cin >> e;

    for (i = 0; i < v; i++)
    {
        for (j = 0; j < v; j++)
            g[i][j] = 0;
    }

    cout << "Enter " << e << " edges (vertex pairs):" << endl;
    for (i = 0; i < e; i++)
    {
        cin >> u >> w;
        if (u >= 1 && u <= v && w >= 1 && w <= v)
        {
            g[u - 1][w - 1] = 1;
            g[w - 1][u - 1] = 1;
        }
        else
        {
            cout << "Invalid edge (" << u << ", " << w << ") skipped." << endl;
        }
    }

    cout << "Adjacency Matrix:" << endl;
    for (i = 0; i < v; i++)
    {
        for (j = 0; j < v; j++)
            cout << g[i][j] << " ";
        cout << endl;
    }

    return 0;
}
