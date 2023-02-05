/*
kth_symbol.cpp
03 February 2023
Fri 21:56
https://leetcode.com/problems/k-th-symbol-in-grammar/description/
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
// string occurence(int n, string s)
// {
//     if (n == 0)
//         return "";
//         return replace(s.begin(),s.end(),'0','10')
// }
// int kthGrammar(int n, int k)
// {
//     string num = to_string(n) + "";
// }
void solve()
{
    string s;
    cin >> s;
    replace(s.begin(), s.end(), '1', '5');
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    //  cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}