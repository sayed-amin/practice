/*
longet_common_subsequence.cpp
28 June 2022
Tue 20:44
https://leetcode.com/problems/longest-common-subsequence/
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int func(int i, int j, string &a, string &b)
{
    if (i < 0 || j < 0)
        return 0;

    int ans = -1;
    if (a[i] == b[j])
    {
        ans = max(ans, func(i - 1, j - 1, a, b) + 1);
    }
    ans = max(ans, func(i - 1, j, a, b));
    ans = max(ans, func(i, j - 1, a, b));
    return ans;
}
int longestCommonSubsequence(string text1, string text2)
{
    return func(text1.size() - 1, text2.size() - 1, text1, text2);
}
void solve()
{
    string a, b;
    cin >> a >> b;
    cout << longestCommonSubsequence(a, b);
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}