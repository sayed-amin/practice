#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n, m;
    cin >> n >> m;
    vector<vector<int>> vec(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> vec[i][j];
        }
    }
    if (n == 1)
    {
        cout << vec[0][0] << endl;
        return 0;
    }
    int left = 0, right = m - 1, top = 0, bottom = n - 1;
    while (left <= right and top <= bottom)
    {
        // top row
        for (int i = left; i <= right; i++)
        {
            cout << vec[top][i] << " ";
        }
        top++;
        // right column
        for (int i = top; i <= bottom; i++)
        {
            cout << vec[i][right] << " ";
        }
        right--;
        // bottom row

        if (top <= bottom)
        {
            for (int i = right; i >= left; i--)
            {
                cout << vec[bottom][i] << " ";
            }
            bottom--;
        }
        if (left <= right)
        {
            for (int i = bottom; i >= top; i--)
            {
                cout << vec[i][left] << " ";
            }
            left++;
        }
    }
    cout << endl;

    return 0;
}