#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int, int> &a, pair<int, int> &b)
{
    return a.first < b.first;
}
void solve()
{
    int n;
    cin >> n;
    map<int, vector<pair<int, int>>> m;
    for (int i = 0; i < n; i++)
    {
        int l, r, v;
        cin >> l >> r >> v;
        m[v].push_back({l, 1});
        m[v].push_back({r + 1, -1});
    }
    for (auto i : m)
    {

        vector<pair<int, int>> temp = i.second;
        sort(temp.begin(), temp.end(), cmp);
        int count = 0;
        int last = -1;
        // cout << i.first << " ";
        for (auto j : temp)
        {
            if (j.first != last and count >= 3)
            {
                cout << "NO" << endl;
                return;
            }
            // cout << j.first << " ";
            // cout << j.second << endl;

            last = j.first;
            count += j.second;
        }
    }
    cout << "YES" << endl;
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