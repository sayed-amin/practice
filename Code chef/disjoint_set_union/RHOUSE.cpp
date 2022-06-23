// pratice dsu
#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int> par(1e5), siz(1e5);
const int MOD = 1e9 + 7;
void make(int i)
{
    par[i] = i;
    siz[i] = 1;
}
int find(int v)
{
    if (v == par[v])
        return par[v];
    return par[v] = find(par[v]);
}
void Union(int a, int b)
{
    a = find(a);
    b = find(b);
    if (a != b)
    {
        if (siz[a] < siz[b])
            swap(a, b);
        par[b] = a;
        siz[a] += siz[b];
    }
}
void solve()
{
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        make(i);
    }
    string s;
    cin >> s;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'R')
        {
            for (int j = i + 1; j < n; j++)
            {
                if (s[j] == 'R')
                {
                    Union(i + 1, j + 1);
                }
            }
            break;
        }
    }
    vector<pair<int, pair<int, int>>> edges(n);
    int ans = 0;

    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        edges.push_back({w, {u, v}});
    }
    sort(edges.begin(), edges.end());

    for (auto &edge : edges)
    {
        int w = edge.first;
        int u = (edge.second.first);
        int v = (edge.second.second);

        int u1 = find(u);
        int v1 = find(v);
        if ((u1 != v1) || w <= 0)
        {
            Union(u1, v1);
            ans += w;
        }
    }
    cout << ans << endl;
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