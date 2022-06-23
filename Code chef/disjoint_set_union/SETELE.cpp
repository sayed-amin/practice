//
#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int> par(1e5), siz(1e5);
vector<pair<int, pair<int, int>>> edges;
void make(int v)
{
    par[v] = v;
    siz[v] = 1;
}
int find(int v)
{
    if (v == par[v])
        return par[v];
    return par[v] = find(par[v]);
}
void Union(int a, int b)
{
    // a = find(a);
    // b = find(b);
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
    int n;
    cin >> n;

    // par.assign(n + 1, -1);
    // siz.assign(n + 1, 0);
    edges.resize(n);
    int c = 0, s = 0, t = 0;

    for (int i = 1; i <= n; i++)
    {
        make(i);
    }
    for (int i = 1; i <= n - 1; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({w, {u, v}});
    }
    sort(edges.begin(), edges.end());
    for (auto &edge : edges)
    {
        int w = edge.first;
        int u = find(edge.second.first);
        int v = find(edge.second.second);
        c += w;
        s += siz[u] * siz[v] * w;
        t += siz[u] * siz[v];
        if (u != v)
            Union(u, v);
    }
    cout << fixed << setprecision(4) << (double)((double)c - (double)s / (double)t) << endl;
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