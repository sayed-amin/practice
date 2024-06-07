/*
Fibonacci_numbers.cpp
02 June 2024
Sun 13:46

*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int n = 1e5 + 10;
int fib[n];
int fibonaci_number(int n)
{
    if (n == 1 || n == 2)
    {
        return 1;
    }
    if (fib[n] != 0)
    {
        return fib[n];
    }
    return fib[n] = fibonaci_number(n - 1) + fibonaci_number(n - 2);
}
void solve()
{
    int n;
    cin >> n;
    cout << fibonaci_number(n) << endl;
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