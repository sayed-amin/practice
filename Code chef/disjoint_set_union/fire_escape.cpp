//
#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int> par, siz;
const int MOD = 1e9 + 7;
void make(int i)
{
    par[i] = i;
    siz[i] = 1;
}
int find(int a)
{
    if (par[a] == a)
        return par[a];
    return par[a] = find(par[a]);
}
void Union(int a, int b)
{
    a = find(a);
    b = find(b);
    if (a != b)
    {
        if (a < b)
            swap(a, b);
        par[b] = a;
        siz[a] += siz[b];
    }
}
void solve()
{
    int n, m;
    cin >> n >> m;
    par.assign(n + 1, 0);
    siz.assign(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        make(i);
    }
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        Union(u, v);
    }
    map<int, int> ma;
    for (int i = 1; i <= n; i++)
    {
        int a = find(i);
        ma[a]++;
    }
    int ans = 1;
    for (auto &i : ma)
    {
        ans *= siz[i.first] % MOD;
        ans = ans % MOD;
    }
    cout << ma.size() << " " << ans << endl;
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