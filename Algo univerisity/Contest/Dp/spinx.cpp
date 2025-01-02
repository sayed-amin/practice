/*
spinx.cpp
29 December 2024
Sun 17:01

*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve()
{
    int n;
    cin >> n;
    vector<int> nums(n + 1), prefix(n + 1, 0), suff(n + 2, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> nums[i];
        prefix[i] = prefix[i - 1] + nums[i];
    }
    for (int i = n - 1; i >= 1; i--)
    {
        suff[i] += suff[i + 1] + nums[i];
    }
    int q;
    cin >> q;
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        cout << prefix[r] - prefix[l - 1] << endl;
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int testcase = 1;
    // cin >> testcase;
    while (testcase--)
    {
        solve();
    }
    return 0;
}