#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mx = -10000000;
int root = 0;
int n;
vector<int> a;
vector<vector<int>> g;
vector<int> ans;
void dfs(int v, int par, int mw)
{
    if (v == root)
        ans[v] = mx;
    else
        ans[v] = mw - a[v];
    for (auto child : g[v])
    {
        if (child == par)
            continue;

        dfs(child, v, max(mw, a[v]));
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    a.resize(n + 1, 0);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    g.resize(n + 1);
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        if (x == -1)
        {
            root = i;
            continue;
        }
        g[x].push_back(i);
        g[i].push_back(x);
    }
    ans.resize(n + 1, mx);
    dfs(root, -1, mx);
    sort(ans.begin() + 1, ans.end());
    cout << ans[n] << endl;
    return 0;
}