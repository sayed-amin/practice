//
#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int> a;
vector<int> s;

int find(int i)
{
    if (i == a[i])
        return a[i];

    return a[i] = find(a[i]);
}
void Union(int x, int y)
{
    x = find(x);
    y = find(y);
    if (x != y)
    {
        if (s[x] < s[y])
            a[x] = a[y];
        else if (s[y] < s[x])
            a[y] = a[x];
    }
}

void solve()
{
    int n;
    cin >> n;
    a.assign(n + 1, 0);
    s.assign(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i];
        a[i] = i;
    }
    // cout << find(1);
    int q;
    cin >> q;
    while (q--)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            int x;
            cin >> x;
            int ans = find(x);
            cout << ans << endl;
        }
        else
        {
            int x, y;
            cin >> x >> y;
            int tx = find(x);
            int ty = find(y);
            if (tx == ty)
                cout << "Invalid query!" << endl;
            Union(x, y);
        }
    }
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