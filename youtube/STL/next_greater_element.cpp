/*
next_greater_element.cpp
31 January 2023
Tue 07:04
https://www.hackerrank.com/contests/second/challenges/next-greater-element/problem
*/
#include <bits/stdc++.h>

using namespace std;
#define int long long
#define endl "\n"
vector<int> nse(vector<int> v)
{
    vector<int> ans(v.size());
    stack<int> st;

    for (int i = 0; i < v.size(); i++)
    {
        while (!st.empty() && v[i] > v[st.top()])
        {
            ans[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    while (!st.empty())
    {
        ans[st.top()] = -1;
        st.pop();
    }
    return ans;
}
void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    vector<int> ans = nse(v);
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " " << (ans[i] == -1 ? -1 : v[ans[i]]) << endl;
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}