// binary search
#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m, k;
vector<int> before;
vector<int> after;
bool isfeasible(int minutes)
{
    vector<int> v(m);
    for (int i = 0; i < m; i++)
    {
        if (minutes - before[i] < 0)
            v[i] = 0;
        else
        {
            v[i] = 1 + (minutes - before[i]) / after[i];
        }
    }
    sort(v.begin(), v.end(), greater<int>());
    int val = 0;
    for (int i = 0; i < min(n, m); i++)
    {
        val += v[i];
    }
    return val >= k;
}
void solve()
{
    cin >> m >> n >> k;
    before.resize(m);
    after.resize(m);
    for (int i = 0; i < m; i++)
        cin >> before[i];
    for (int i = 0; i < m; i++)
        cin >> after[i];
    int low = 1, high = 1e15, mid;
    while (high - low > 1)
    {
        mid = low + (high - low) / 2;
        if (isfeasible(mid))
        {
            high = mid;
        }
        else
            low = mid + 1;
    }
    if (isfeasible(low))
        cout << low << endl;
    else
        cout << high << endl;
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