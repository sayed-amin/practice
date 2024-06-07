/*
nearest_largest_number.cpp
31 May 2024
Fri 20:29

*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve()
{
    int n;
    cin >> n;
    vector<int> heights(n);
    for (int i = 0; i < n; i++)
    {
        cin >> heights[i];
    }
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() and st.top() <= heights[i])
        {
            st.pop();
        }
        if (!st.empty())
        {
            cout << st.top() << " ";
        }
        else
        {
            cout << -1 << " ";
        }
        st.push(heights[i]);
    }
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