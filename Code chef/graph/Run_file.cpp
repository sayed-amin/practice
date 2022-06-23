#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<vector<int>> g;
vector<int> h, d, subtree;
vector<int> path(int x)
{
    vector<int> lenght;
    while (x)
    {
        lenght.push_back(x & 1);
        x >>= 1;
    }
    reverse(lenght.begin(), lenght.end());
    return lenght;
}
void solve()
{
    int u, v;
    cin >> u >> v;
    vector<int> a = path(u);
    vector<int> b = path(v);
    int lca = 0, depth = min(a.size(), b.size());
    for (int i = 0; i < depth; i++)
    {
        if (a[i] == b[i])
            lca++;
        else
            break;
    }
    cout << a.size() + b.size() - 2 * lca << endl;
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
