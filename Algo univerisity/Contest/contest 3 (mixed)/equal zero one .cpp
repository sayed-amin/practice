/*
equal zero one .cpp
22 June 2024
Sat 21:26

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
    unordered_map<int, int> prefixSumCount;
    int prefixSum = 0;
    int count = 0;
    prefixSumCount[0] = 1;
    for (auto num : a)
    {

        if (num == 0)
        {
            prefixSum += -1;
        }
        else
        {
            prefixSum += num;
        }

        if (prefixSumCount.find(prefixSum) != prefixSumCount.end())
        {
            count += prefixSumCount[prefixSum];
        }

        prefixSumCount[prefixSum]++;
    }
    cout << count << endl;
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