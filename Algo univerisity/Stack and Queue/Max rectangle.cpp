/*
largest element in histogram.cpp
07 June 2024
Fri 22:14

*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n), left(n, -1);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    stack<int> st;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        while (st.size() and arr[st.top()] >= arr[i])
        {
            st.pop();
        }
        if (st.size())
        {
            left[i] = st.top();
        }
        st.push(i);
    }
    while (st.size())
        st.pop();
    for (int i = n - 1; i >= 0; i--)
    {
        while (st.size() and arr[st.top()] >= arr[i])
        {
            st.pop();
        }
        int right = n;
        if (st.size())
        {
            right = st.top();
        }
        ans = max(ans, (right - left[i] - 1) * arr[i]);
        st.push(i);
    }
    cout << ans << endl;
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