// binar-search spoj
#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, f;
const int N = 1e4 + 10;
vector<int> pies(N);
void solve()
{
    cin >> n >> f;
    for (int i = 0; i < n; i++)
    {
        cin >> pies[i];
    }
    int low = 0, high = 1e4, mid;
    while (high - low > 1)
    {
    }
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