//
#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> g(n + 1);
    set<int> s;
    vector<int> a(n + 1);
    vector<int> ans(n + 1, 0);
    map<int, int> m;

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        s.insert(a[i]);
        m[a[i]] = i;
    }
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
    {

        s.erase(a[i]);
        for (auto child : g[i])
        {
            s.erase(a[child]);
        }

        if (!s.empty())
        {

            ans[i] = *s.rbegin();
        }
        s.insert(a[i]);
        for (auto child : g[i])
        {
            s.insert(a[child]);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << m[ans[i]] << " ";
    }
    cout << endl;
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