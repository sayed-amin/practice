/*
dsu.cpp
02 July 2022
Sat 07:32
disjion set union
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N = 1e5 + 10;
int par[N];
int siz[N];
multiset<int> sizes;
void make(int v)
{
    par[v] = v;
    siz[v] = 1;
    sizes.insert(1);
}
int find(int v)
{
    if (v == par[v])
        return v;
    return par[v] = find(par[v]);
}
void merge(int a, int b)
{
    sizes.erase(sizes.find(siz[a]));
    sizes.erase(sizes.find(siz[b]));
    sizes.insert(siz[a] + siz[b]);
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
        merge(a, b);
        siz[a] += siz[b];
    }
}
void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        make(i);
    }
    int k;
    cin >> k;
    while (k--)
    {
        int i, j;
        cin >> i >> j;
        Union(i, j);
        if (sizes.size() == 1)
            cout << 0 << endl;
        else
        {
            int min = *sizes.begin();
            int max = *(--sizes.end());
            cout << max - min << endl;
        }
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