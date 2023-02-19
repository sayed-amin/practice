/*
min_spaning_tree.cpp
02 July 2022
Sat 08:15
https://codeforces.com/contest/1245/problem/D
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N = 1e5 + 10;
int par[N];
int siz[N];
void make(int v)
{
    par[v] = v;
    siz[v] = 1;
}
int find(int v)
{
    if (v == par[v])
        return v;
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
    int n;
    cin >> n;
    vector<pair<int, int>> cities(n + 1);
    vector<pair<int, pair<int, int>>> edges;
    for (int i = 1; i <= n; i++)
    {
        cin >> cities[i].first >> cities[i].second;
    }
    vector<int> c(n + 1), k(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> c[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> k[i];
    }
    for (int i = 1; i <= n; i++)
    {
        edges.push_back({c[i], {0, i}});
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            int dist = k[i] + k[j];
            int d = abs(cities[i].first - cities[j].first) + abs(cities[i].second - cities[j].second);
            int cost = d * dist;
            edges.push_back({cost, {i, j}});
        }
    }
    sort(edges.begin(), edges.end());
    int cost = 0;
    vector<int> p;
    vector<pair<int, int>> connection;
    for (int i = 1; i <= n; i++)
        make(i);
    for (auto &edge : edges)
    {
        int w = edge.first;
        int u = edge.second.first;
        int v = edge.second.second;
        if (find(u) == find(v))
            continue;
        Union(u, v);
        cost += w;
        if (u == 0 || v == 0)
        {
            p.push_back(max(u, v));
        }
        else
        {
            connection.push_back({u, v});
        }
    }
    cout << cost << endl;
    cout << p.size() << endl;
    for (auto i : p)
    {
        cout << i << " ";
    }
    cout << endl;
    cout << connection.size() << endl;
    for (auto i : connection)
    {
        cout << i.first << " " << i.second << " ";
    }
    cout << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}