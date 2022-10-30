/*
array_manipulation.cpp
21 August 2022
Sun 05:53
https://www.hackerrank.com/challenges/crush/problem
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> arr(n + 1);
    while (m--)
    {
        int a, b, k;
        cin >> a >> b >> k;

        arr[a] += k;
        if (b != n)
            arr[b + 1] += -k;
    }
    for (int i = 2; i <= n; i++)
    {
        arr[i] += arr[i - 1];
    }
    int ans = -1;
    for (int i = 1; i <= n; i++)
        ans = max(ans, arr[i]);
    cout << ans << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    //  cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}