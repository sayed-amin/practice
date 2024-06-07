/*
BracketMatching.cpp
25 May 2024
Sat 19:41

*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve()
{
    string s;
    cin >> s;
    // first -> brakcet  second -> position
    vector<int> ans(s.size(), -1);
    stack<pair<char, int>> st;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
        {
            st.push({'(', i});
        }
        else
        {

            if (s[i] == ')' and !st.empty())
            {
                pair<char, int> top_element = st.top();
                ans[top_element.second] = i;
                ans[i] = top_element.second;
                st.pop();
            }
        }
    }
    for (auto &i : ans)
    {
        cout << i << " ";
    }
    cout << endl;
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