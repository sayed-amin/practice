/*
sumoffirstnnaturalnumber.cpp
26 May 2024
Sun 14:32

*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void towerOfHanoi(int n, char a, char b, char c)
{

    if (n == 1)
    {
        cout << "Move disk 1 from rod " << a << " to rod " << b << endl;
        return;
    }

    towerOfHanoi(n - 1, a, c, b);

    cout << "Move disk " << n << " from rod " << a << " to rod " << b << endl;

    towerOfHanoi(n - 1, c, b, a);
}
int func(int n)
{
    if (n <= 0)
    {
        return 0;
    }
    return func(n - 1) + n;
}
int fact(int n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }
    return fact(n - 1) + fact(n - 2);
}
int ncr(int n, int r)
{
    if (r == 0 || r == n)
    {
        retunr 1;
    }
    return ncr(n - 1, r - 1) + ncr(n - 1, r);
}
void solve()
{
    int n, r;
    cin >> n >> r;
    cout << fact(n) / (fact(n - r) * fact(r));
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int testcase = 1;
    //   cin >> testcase;
    while (testcase--)
    {
        solve();
    }
    return 0;
}