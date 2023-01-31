/*
brackets.cpp
30 January 2023
Mon 23:22

*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
// first method
string isBalanced1(string s)
{
    stack<char> st;
    bool ans = true;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
            st.push(')');
        else if (s[i] == '{')
            st.push('}');
        else if (s[i] == '[')
            st.push(']');

        if (s[i] == ')' || s[i] == '}' || s[i] == ']')
        {
            // cout << 1 << endl;
            if (st.empty())
                return "NO";
            else if (!st.empty())
            {
                if (s[i] != st.top())
                {
                    ans = false;
                }
                st.pop();
            }
        }
    }
    if (ans and st.empty())
        return "YES";
    else
        return "NO";
}
// second method
unordered_map<char, int> m = {{'(', -1}, {'{', -2}, {'[', -3}, {')', 1}, {'}', 2}, {']', 3}};
string isBalanced(string s)
{
    stack<char> st;
    for (auto bracket : s)
    {
        if (m[bracket] < 0)
            st.push(bracket);
        else
        {
            if (st.empty())
                return "NO";
            char top = st.top();
            st.pop();
            if (m[bracket] + m[top] != 0)
                return "NO";
        }
    }
    if (st.empty())
        return "YES";
    else
        return "NO";
}
void solve()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        cout << isBalanced(s) << endl;
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