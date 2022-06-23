#include <iostream>
#include <vector>
using namespace std;
#define int long long
vector<int> par;
vector<int> siz;

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
    int n, m;
    cin >> n >> m;
    par.assign(n, -1);
    siz.resize(n);

    for (int i = 0; i < n; i++)
    {
        make(i);
    }
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        Union(a, b);
    }
    //     cout << par[3] << endl;
    //     cout << find(3);
    //     cout << find(2);
    int q;
    cin >> q;
    while (q--)
    {
        int x, y;
        cin >> x >> y;
        if (find(x) == find(y))
            cout << "YO" << endl;
        else
            cout << "NO" << endl;
    }
}
// }
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