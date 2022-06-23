//
#include <bits/stdc++.h>
using namespace std;
#define int long long
bool cmp(pair<int, int> p1, pair<int, int> p2)
{
    return p1.first > p2.first;
}
void solve()
{

    vector<pair<int, int>> a;

    for (int i = 1; i <= 10; i++)
    {
        int b;
        cin >> b;
        if (b != 0)
            a.push_back({i, b});
    }
    int k;
    cin >> k;
    sort(a.begin(), a.end(), cmp);
    int i = 1;
    int ans = 0;

    // for (auto i : a)
    //     cout << i.first << " " << i.second << endl;

    for (auto i = a.begin(); i != a.end(); i++)
    {
        if (k - i->second >= 0)
            k -= i->second;
        else
        {
            ans = i->first;
            break;
        }
    }
    cout << ans << endl;
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