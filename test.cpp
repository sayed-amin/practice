#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n, m;
    cin >> n >> m;
    vector<vector<int>> matrix(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> matrix[i][j];
        }
    }
    for (int i = 2; i <= n; i++)
    {
        for (int j = 2; j <= m; j++)
        {
            if (matrix[i][j] != matrix[i - 1][j - 1])
            {
                cout << 0 << endl;
                return 0;
            }
        }
    }
    cout << 1 << endl;

    return 0;
}