// https://www.codechef.com/submit/CM164364
#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int n, k;
    cin >> n >> k;
    map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        m[x]++;
    }

    int can_have = 0;
    for (auto &i : m)
    {
        can_have += i.second - 1;
    }
    if (k <= can_have)
        cout << m.size() << endl;
    else
        cout << m.size() - (k - can_have) << endl;
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