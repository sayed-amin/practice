/*
FROGV.cpp
23 June 2022
Thu 16:40
first dp
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void make(int n)
{
}
void solve()
{
    int n, k, p;
    cin >> n >> k >> p;
    vector<pair<int, int>> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        a[i] = {x, i};
    }
    sort(a.begin(), a.end());
    unordered_map<int, int> new_index;
    for (int i = 1; i <= n; i++)
    {
        new_index[a[i].second] = i;
    }
    vector<int> dp(n + 1, 0);
    for (int i = 2; i <= n; i++)
    {
        if (a[i].first - a[i - 1].first <= k)
            dp[i] = 1 + dp[i - 1];
    }
    while (p--)
    {
        int x, y;
        cin >> x >> y;
        if (x == y)
            cout << "yes" << endl;
        else
        {
            // cout << 1 << endl;
            int a = new_index[x];
            int b = new_index[y];
            if (b < a)
            {
                swap(b, a);
            }
            if (b - a > dp[b])
                cout << "no" << endl;
            else
                cout << "yes" << endl;
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