#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;
vector<vector<int>> g;
vector<int> sum;
vector<int> ans;
vector<int> counts;
void dfs(int v, int par = -1)
{

    counts[v] = 1;
    for (auto child : g[v])
    {
        if (child == par)
            continue;
        dfs(child, v);
        counts[v] += counts[child];
        sum[v] += (sum[child] + counts[child]);
    }
}
void cal_ans(int v, int par = -1, int contriabove = 0)
{
    ans[v] = contriabove + sum[v];
    int total = ans[v];
    for (auto child : g[v])
    {
        if (child == par)
            continue;
        int above = total - sum[child] + n - 2 * counts[child];
        cal_ans(child, v, above);
    }
}
void solve()
{

    cin >> n;
    g.resize(n);
    sum.assign(n, 0);
    ans.assign(n, 0);
    counts.assign(n, 0);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(0);
    cal_ans(0);
    for (int i : ans)
        cout << i << " ";
    cout << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}