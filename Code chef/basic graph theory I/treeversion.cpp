#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<int> a;
vector<vector<int>> g;
vector<int> count1, count0;

void dfs(int v, int par = -1)
{
    int c0 = 0, c1 = 0;
    if (a[v] == 0)
        c0++;
    else
        c1++;
    for (auto child : g[v])
    {
        if (par == child)
            continue;
        dfs(child, v);
        c0 += count0[child];
        c1 += count1[child];
    }
    count0[v] = c0;
    count1[v] = c1;
}
int treeversion(int src, int par = -1)
{
    if (par != -1 && g[src].size() == 1)
        return 0;
    vector<pair<int, int>> count;
    int intervalinversion = 0, subtreeinversion = 0, ext = 0;
    for (auto child : g[src])
    {
        if (child == par)
            continue;
        intervalinversion += treeversion(child, src);
        count.push_back({count0[child], count1[child]});
        ext += count0[child];
    }
    sort(count.begin(), count.end(), [](pair<int, int> &b, pair<int, int> &c)
         {
int inv1=b.second*c.first;
int inv2=b.first*c.second;
if(inv1<inv2)
return 1;
return 0; });
    int ans = 0;
    if (a[src] == 1)
        ans += ext;
    for (auto i : count)
    {
        ext -= i.first;
        subtreeinversion += (i.second * ext);
    }
    ans = ans + subtreeinversion + intervalinversion;
    return ans;
}
void solve()
{
    int n;
    cin >> n;
    a.assign(n + 1, 0);
    g.resize(n + 1);
    count1.assign(n + 1, 0);
    count0.assign(n + 1, 0);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1);
    cout << treeversion(1) << endl;
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
        g.clear();
        a.clear();
        solve();
    }
    return 0;
}