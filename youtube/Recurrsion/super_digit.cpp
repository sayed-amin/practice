/*
super_digit.cpp
03 February 2023
Fri 16:35
https://www.hackerrank.com/challenges/recursive-digit-sum/problem
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
// digitsum(n) n%10 + digitsum(n/10)
int digitsum(int n)
{
    if (n == 0)
        return 0;
    return digitsum(n / 10) + (n % 10);
}
int superDigit(string n, int k)
{
    string new_s = "";
    while (k--)
    {
        new_s += n;
    }
    int num;
    num = stoi(new_s);
    int ans = digitsum(num);
    while ((ans / 10) != 0)
    {
        ans = digitsum(ans);
    }
    return ans;
}

void solve()
{
    cout << superDigit("9845", 4);
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