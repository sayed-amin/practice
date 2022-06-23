//
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 25;
vector<int> Piles(N);
int hours, n;
bool can_eat(int min_time)
{
    int hours_ct = 0;
    for (int i = 0; i < n; i++)
    {
        hours_ct += ((Piles[i] + min_time - 1) / (min_time * 1.0));
    }
    return hours_ct <= hours;
}
void solve()
{

    cin >> n;
    cin >> hours;
    int mx_hours = -1;
    for (int i = 0; i < n; i++)
    {
        cin >> Piles[i];
        mx_hours = max(mx_hours, Piles[i]);
    }
    int low = 1, high = mx_hours, mid;
    int ans = mx_hours;

    while (low <= high)
    {
        mid = (high + low) / 2;
        if (can_eat(mid))
        {
            ans = min(ans, mid);
            high = mid - 1;
        }
        else
            low = mid + 1;
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