/*
candies.cpp
18 May 2024
Sat 17:18

*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
bool isPossible(const vector<int> &candies, int N, int M, int mid)
{
    int count = 1;
    int current_sum = 0;

    for (int i = 0; i < N; ++i)
    {
        if (current_sum + candies[i] > mid)
        {
            // Start a new block
            count++;
            current_sum = candies[i];
            // If more blocks are required than available, return false
            if (count > M)
                return false;
        }
        else
        {
            current_sum += candies[i];
        }
    }
    return true;
}
int minimizeMaxCandies(const vector<int> &candies, int N, int M)
{
    if (M > N)
        return -1; // Not enough boxes to divide among M children

    int maxCandy = *max_element(candies.begin(), candies.end());
    int sumCandies = accumulate(candies.begin(), candies.end(), 0);

    int low = maxCandy, high = sumCandies, result = high;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (isPossible(candies, N, M, mid))
        {
            result = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return result;
}
void solve()
{
    int N, M;
    cin >> N >> M;
    vector<int> candies(N);

    for (int i = 0; i < N; ++i)
    {
        cin >> candies[i];
    }

    int result = minimizeMaxCandies(candies, N, M);
    cout << result << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int testcase = 1;
    //  cin >> testcase;
    while (testcase--)
    {
        solve();
    }
    return 0;
}