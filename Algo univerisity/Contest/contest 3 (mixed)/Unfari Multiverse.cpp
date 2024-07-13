/*
Unfari Multiverse.cpp
22 June 2024
Sat 22:17

*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    vector<int> leftMax(n), rightMax(n), leftMin(n), rightMin(n);
    stack<int> s;
    for (int i = 0; i < n; ++i)
    {
        while (!s.empty() && arr[s.top()] <= arr[i])
        {
            s.pop();
        }
        leftMax[i] = s.empty() ? -1 : s.top();
        s.push(i);
    }
    while (!s.empty())
        s.pop();
    for (int i = n - 1; i >= 0; --i)
    {
        while (!s.empty() && arr[s.top()] < arr[i])
        {
            s.pop();
        }
        rightMax[i] = s.empty() ? n : s.top();
        s.push(i);
    }
    while (!s.empty())
        s.pop();
    for (int i = 0; i < n; ++i)
    {
        while (!s.empty() && arr[s.top()] >= arr[i])
        {
            s.pop();
        }
        leftMin[i] = s.empty() ? -1 : s.top();
        s.push(i);
    }

    while (!s.empty())
        s.pop();
    for (int i = n - 1; i >= 0; --i)
    {
        while (!s.empty() && arr[s.top()] > arr[i])
        {
            s.pop();
        }
        rightMin[i] = s.empty() ? n : s.top();
        s.push(i);
    }

    int totalUnfairness = 0;
    for (int i = 0; i < n; ++i)
    {
        int maxContribution = (i - leftMax[i]) * (rightMax[i] - i) * arr[i];
        int minContribution = (i - leftMin[i]) * (rightMin[i] - i) * arr[i];
        totalUnfairness += maxContribution - minContribution;
    }

    cout << totalUnfairness << endl;
    ;
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