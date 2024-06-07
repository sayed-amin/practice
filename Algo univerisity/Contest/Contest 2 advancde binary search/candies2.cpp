/*
candies2.cpp
18 May 2024
Sat 20:15

*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
bool isPossible(vector<int> &candies, int n, int m, int mid)
{
    int count = 1;
    int current_sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (current_sum + candies[i] > mid)
        {
            count++;
            current_sum = candies[i];
            if (count > m)
                return false;
        }
        else
        {
            current_sum += candies[i];
        }
    }
    return true;
}
int minimizeMaxCandies(vector<int> &candies, int n, int m)
{
    if (m > n)
    {
        return -1;
    }
    int maxCandy = *max_element(candies.begin(), candies.end());
    int sumCandies = accumulate(candies.begin(), candies.end(), 0);
    int low = maxCandy, high = sumCandies;
    while (low + 1 < high)
    {
        int mid = low + (high - low) / 2;
        if (isPossible(candies, n, m, mid) == 0)
        {
            low = mid;
        }
        else
        {
            high = mid;
        }
    }
    if (isPossible(candies, n, m, low))
        return low;
    return high;
}
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> candies(n);
    for (int i = 0; i < n; i++)
    {
        cin >> candies[i];
    }
    cout << minimizeMaxCandies(candies, n, m) << endl;
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