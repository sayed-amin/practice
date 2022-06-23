#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, m;
vector<vector<int>> g;
vector<int> c;
vector<bool> vis;
int mom = 1e5;
void dfs(int v)
{
    vis[v] = true;
    // if (c[v] >= 0)
    //     flag = true;
    if (c[v] >= 0 and mom > c[v])
        mom = c[v];
    for (auto child : g[v])
    {
        if (vis[child])
            continue;

        dfs(child);
    }
}
void solve()
{

    cin >> n >> m;
    g.resize(n + 1);
    c.resize(n + 1);
    vis.assign(n + 1, false);
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for (int i = 1; i <= n; i++)
        cin >> c[i];
    int sum = 0;
    int prev = 1e5;
    int count = 0;
    int b = 0;
    for (int i = 1; i <= n; i++)
    {
        if (vis[i])
        {
            continue;
        }

        dfs(i);
        count++;
        if (mom == 1e5)
        {
            b = 1;
            break;
        }
        //  cout << mom << endl;
        sum += mom;
        prev = min(prev, mom);
        // cout << prev << " " << mom << endl;
        mom = 1e5;

        // if (ans == false)
        // {
        //     flag = 1;
        //     break;
        // }
    }
    // cout << count << endl;
    // cout << prev << endl;
    if (count == 1)
        cout << 0 << endl;
    else if (count > 1 and b == 1)
        cout << -1 << endl;
    else
    {
        // if (count == 2)
        //     cout << sum << endl;
        // else
        cout << sum + (count - 2) * prev << endl;
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}