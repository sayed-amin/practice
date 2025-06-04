/*
Circular Subarray Sum.cpp
04 January 2025
Sat 15:04
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
    int totalSum = 0;
    int linearMaxSubarraySum = LLONG_MIN, linearMinSubarraySum = LLONG_MAX;
    int currentMax = 0, currentMin = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        totalSum += a[i];

        // Kadane's for max subarray sum
        currentMax = max(currentMax + a[i], a[i]);
        linearMaxSubarraySum = max(linearMaxSubarraySum, currentMax);

        // Kadane's for min subarray sum
        currentMin = min(currentMin + a[i], a[i]);
        linearMinSubarraySum = min(linearMinSubarraySum, currentMin);
    }

    // Handle edge case where all elements are negative
    if (linearMaxSubarraySum < 0)
    {
        cout << linearMaxSubarraySum << endl;
        return;
    }

    // Maximum of linear or circular subarray sum
    int circularMaxSubarraySum = totalSum - linearMinSubarraySum;
    cout << max(linearMaxSubarraySum, circularMaxSubarraySum) << endl;
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
