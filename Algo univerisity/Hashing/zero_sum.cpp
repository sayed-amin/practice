/*
zero_sum.cpp
01 June 2024
Sat 20:05

*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    unordered_set<int> prefix_sums;
    int prefix_sum = 0;
    for (int &num : a)
    {
        prefix_sum += num;
        if (prefix_sum == 0 || prefix_sums.find(prefix_sum) != prefix_sums.end())
        {
            cout << "YES" << endl;
            return;
        }
        prefix_sums.insert(prefix_sum);
    }
    cout << "NO" << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int testcase = 1;
    //   cin >> testcase;
    while (testcase--)
    {
        solve();
    }
    return 0;
}