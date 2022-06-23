// binary search spoj
#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, c;
const int N = 1e5 + 10;
vector<int> cows(N);
bool isvalid(int dist)
{
    int laspos = -1;
    int cows_count = c;
    for (int i = 0; i < n; i++)
    {
        if (cows[i] - laspos >= dist || laspos == -1)
        {
            cows_count--;
            laspos = cows[i];
        }
        if (cows_count == 0)
            break;
    }
    return cows_count == 0;
}
void solve()
{
    cin >> n >> c;
    for (int i = 0; i < n; i++)
    {
        cin >> cows[i];
    }
    sort(cows.begin(), cows.begin() + n);
    int low = 0, high = 1e9, mid;
    // TTTTFFFFF
    while (high - low > 1)
    {
        mid = (high + low) / 2;
        if (isvalid(mid))
        {
            low = mid;
        }
        else
        {
            high = mid - 1;
        }
    }
    if (isvalid(high))
        cout << high << endl;
    else
        cout << low << endl;
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