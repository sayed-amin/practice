/*
seive.cpp
05 August 2023
Sat 20:55
'
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N = 1e5 + 7;
vector<int> isprime(N, 1);
void solve()
{
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    isprime[1] = 0;
    for (int i = 2; i < N; i++)
    {
        if (isprime[i])
        {
            for (int j = 2 * i, j < N; j += i)
            {
                isprime[j] = false;
            }
        }
    }
    while (t--)
    {
        solve();
    }
    return 0;
}