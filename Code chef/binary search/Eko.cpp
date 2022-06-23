//
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 10;
int n, m;
vector<int> tree(N);
bool issufficient(int h)
{
    int total = 0;
    for (int i = 0; i < n; i++)
    {
        if (tree[i] > h)
            total += (tree[i] - h);
    }
    return total >= m;
}
void solve()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> tree[i];
    }
    int low = 0, high = 1e9, mid;
    while (high - low > 1)
    {
        mid = (high + low) / 2;
        if (issufficient(mid))
        {
            low = mid;
        }
        else
        {
            high = mid - 1;
        }
    }
    if (issufficient(high))
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
    //   cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}