// binary search lowerbound
#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    vector<int> left, right;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] == 1)
            right.push_back(i);
        else if (a[i] == 2)
            left.push_back(i);
    }
    while (m--)
    {
        int dest;
        cin >> dest;
        int dist1 = 1e15, dist2 = 1e15;
        auto left_it = lower_bound(left.begin(), left.end(), dest);
        if (left_it != left.end())
            dist1 = *left_it - dest;
        auto right_it = lower_bound(right.begin(), right.end(), dest);
        if (right_it != right.end() and *right_it == dest)
        {
            dist2 = 0;
        }
        else
        {
            if (right_it != right.begin())
            {
                right_it--;
                dist2 = dest - *right_it;
            }
        }

        int ans = min(dist1, dist2);
        if (ans == 1e15)
            ans = -1;
        if (dest == 1)
            ans = 0;
        cout << ans << " ";
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