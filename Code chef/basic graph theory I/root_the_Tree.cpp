#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int n;
    cin >> n;
    vector<int> g(n + 1, 0);
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        g[v]++;
    }
    int count = 0;
    for (int i = 1; i <= n; i++)
    {
        if (g[i] == 0)
            count++;
    }
    cout << count - 1 << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}