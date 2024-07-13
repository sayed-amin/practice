/*
valid palindrome.cpp
07 July 2024
Sun 09:38

*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
class Solution
{
public:
    bool isPalindrome(string s)
    {
        int low = 0, high = s.size() - 1;
        while (low < high)
        {
            while (!isalnum(s[low]) and low < high)
            {
                low++;
            }
            while (!isalnum(s[high]) and low < high)
            {
                high--;
            }
            if (tolower(s[low]) != tolower(s[high]))
            {
                return false;
            }
            low++, high--;
        }
        return true;
    }
};
void solve()
{
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int testcase = 1;
    cin >> testcase;
    while (testcase--)
    {
        solve();
    }
    return 0;
}