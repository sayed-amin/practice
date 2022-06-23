// sorting
#include <bits/stdc++.h>
using namespace std;
#define int long long
bool cmp(pair<int, int> p1, pair<int, int> p2)
{
    if (p1.first == p2.first)
        return p2.first < p1.first;
    return p1.first > p2.first;
}
void solve()
{
    int n, m, x;
    cin >> n >> m >> x;
    vector<pair<int, int>> arr;
    multiset<int> ans;

    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        if (a >= m)
            ans.insert(i);
        else
            arr.push_back({a, i});
    }
    sort(arr.begin(), arr.end(), cmp);
    if (ans.size() < x)
    {
        for (int i = 0; i < ans.size() - x; i++)
        {
            ans.insert(arr[i].second);
        }
    }
    cout << ans.size() << " ";
    for (auto i : ans)
    {
        cout << i + 1 << " ";
    }
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