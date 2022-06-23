#include <bits/stdc++.h>
using namespace std;

int a = 0;
pair<int, int> sol(vector<vector<int>> &g, int wt[], int s, int par = -1)
{
    if (par != -1 && g[s].size() == 1)
    {
        return make_pair(wt[s], wt[s]);
    }
    pair<int, int> ans = {INT_MAX, INT_MIN};
    for (auto child : g[s])
    {
        if (child != par)
        {
            pair<int, int> temp = sol(g, wt, child, s);
            ans.first = min(ans.first, temp.first);
            ans.second = max(ans.second, temp.second);
        }
    }
    a = max({a, wt[s] - ans.first, ans.second - wt[s]});
    ans.first = min(ans.first, wt[s]);
    ans.second = max(ans.second, wt[s]);
    return ans;
}
void solve()
{
    int n;
    cin >> n;
    int wt[n + 1];
    int p[n + 1];
    int root = -1;
    vector<vector<int>> g(n + 1);

    for (int i = 1; i <= n; i++)
    {
        cin >> wt[i];
    }

    for (int i = 1; i <= n; i++)
    {
        cin >> p[i];
        if (p[i] == -1)
        {
            root = i;
            continue;
        }
        g[p[i]].push_back(i);
        g[i].push_back(p[i]);
    }
    sol(g, wt, root);
    cout << a << endl;
    a = 0;
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