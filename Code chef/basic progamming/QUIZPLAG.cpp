/*
QUIZPLAG.cpp
25 July 2022
Mon 09:16
basic
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> ans;
    map<int, int> mp;
    for (int i = 0; i < k; i++)
    {
        int x;
        cin >> x;
        if (x <= n and mp[x] == 1)
            ans.push_back(x);
        mp[x]++;
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << " ";
    for (auto &i : ans)
        cout << i << " ";
    cout << endl;
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