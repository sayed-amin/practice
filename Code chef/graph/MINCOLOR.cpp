/*
MINCOLOR.cpp
21 July 2022
Thu 18:55
1700 rating
basic coloring
chess coloring
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

void solve()
{
    int n, m;
    cin >> n >> m;
    int x1, x2, y1, y2;
    cin >> x1 >> y1;
    cin >> x2 >> y2;
    int ans[n + 1][m + 1];
    ans[x1][y1] = 1;
    ans[x2][y2] = 2;
    int col1 = 1, col2 = 2, col3 = 3;
    bool c = (((x1 + y1) & 1) != ((x2 + y2) & 1));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if ((i == x1 and j == y1) || (i == x2 and j == y2))
                continue;
            if (((i + j) & 1) == ((x1 + y1) & 1))
                ans[i][j] = 1;
            else
                ans[i][j] = (c ? 2 : 3);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}