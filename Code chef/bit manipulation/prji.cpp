// bit manilpulation
#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int n;
    cin >> n;
    if (n == 1)
    {
        cout << 0 << endl;
        return;
    }
    // total bit in a number
    int bit = ceil(log2(n * 1.0));
    // cout << bit << endl;
    // total bit - set bit= unset bit
    cout << bit - __builtin_popcount(n) << endl;
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