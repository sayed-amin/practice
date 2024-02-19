/*
T-prime.cpp
14 February 2024
Wed 15:54

We know that prime numbers are positive integers that have exactly two distinct positive divisors. Similarly, we'll call a positive integer t Т-prime, if t has exactly three distinct positive divisors.

You are given an array of n positive integers. For each of them determine whether it is Т-prime or not.

Input
The first line contains a single positive integer, n (1 ≤ n ≤ 105), showing how many numbers are in the array. The next line contains n space-separated integers xi (1 ≤ xi ≤ 1012).

Please, do not use the %lld specifier to read or write 64-bit integers in С++. It is advised to use the cin, cout streams or the %I64d specifier.

Output
Print n lines: the i-th line should contain "YES" (without the quotes), if number xi is Т-prime, and "NO" (without the quotes), if it isn't.

Examples
inputCopy
3
4 5 6
outputCopy
YES
NO
NO

https://codeforces.com/problemset/problem/230/B
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N = 1e6 + 10;
vector<int> isprime(N, 1);
vector<int> divisor(N);
void solve()
{
    int n;
    cin >> n;
    for (int i = 2; i < N; i++)
    {
        if (isprime[i])
        {
            for (int j = 2 * i; j < N; j += i)
            {
                isprime[j] = false;
            }
        }
    }
    set<int> s;
    for (int i = 2; i < N; i++)
    {
        if (isprime[i])
        {
            s.insert(i * i);
        }
    }
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        auto it = s.find(x);
        if (it != s.end())
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
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