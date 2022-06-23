//
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int M = 5e5 + 5;
vector<vector<int>> divs(M);
void pre()
{
    int i, j;
    for (i = 1; i < M; i++)
    {
        for (int j = i; j < M; j = j + i)
        {
            divs[j].push_back(i);
        }
    }
}
void solve()
{

    int n, m, b;
    cin >> n >> m;
    int res = 0;
    for (b = 2; b <= n; b++)
    {
        int x = m - (m % b);
        if (x > 0)
            res += lower_bound(divs[x].begin(), divs[x].end(), b) - divs[x].begin();
        else
            res += b - 1;
    }
    cout << res << endl;
}
int32_t main()
{
    pre();
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