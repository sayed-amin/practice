/*
FROGV(1.2).cpp
23 June 2022
Thu 17:05
using disjoint set union
*/
#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
const int N = 1e5 + 10;
int par[N], siz[N];
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
    // int a = find(a);
    // int b = find(b);
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

    int n, k, p;
    cin >> n >> k >> p;
    vector<pair<int, int>> a(n);
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        make(i);
        a[i].first = x;
        a[i].second = i;
    }

    sort(a.begin(), a.end());
    for (int i = 1; i < n; i++)
    {
        if (a[i].first - a[i - 1].first <= k)
        {
            Union(a[i].second, a[i - 1].second);
        }
    }
    while (p--)
    {
        int a, b;
        cin >> a >> b;
        if (a == b)
            cout << "Yes" << endl;
        else if (find(a) == find(b))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
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