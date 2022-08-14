/*
CIREQ.cpp
25 July 2022
Mon 07:01
basic programming
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    multiset<int> available;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    available.insert(1);
    for (int i = 0; i < n; i++)
    {
        auto it = available.upper_bound(a[i]);
        if (it == available.begin())
        {
            available.insert(2);
        }
        else
        {
            int new_idx = *available.begin() + 1;
            available.erase(available.begin());
            available.insert(new_idx);
        }
    }
    cout << available.size() << endl;
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