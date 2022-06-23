//
#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int n;
    cin >> n;
    vector<int> disc(n);
    for (int i = 0; i < n; i++)
        cin >> disc[i];
    vector<int> top;
    for (int i = 0; i < n; i++)
    {
        int radius = disc[i];
        auto it = upper_bound(top.begin(), top.end(), radius);
        if (it == top.end())
        {
            top.push_back(radius);
        }
        else
        {
            *it = radius;
        }
    }
    cout << top.size() << " ";
    for (auto ele : top)
        cout << ele << " ";
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