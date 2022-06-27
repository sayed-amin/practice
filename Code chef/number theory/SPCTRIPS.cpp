/*
SPCTRIPS.cpp
26 June 2022
Sun 06:02

*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N = 1e5 + 5;
vector<int> isprime(N, 0);
vector<int> primefators(N, 0);
void solve()
{
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 2; i <= n; i++)
    {
        int x = n - (n % i);
        ans += (x % i) * isprime[i];
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    for (int i = 2; i < N; i++)
    {
        if (isprime[i] == 0)
        {
            isprime[i]++;
            for (int j = 2 * i; j < N; j += i)
            {

                isprime[j]++;
            }
        }
    }
    while (t--)
    {
        solve();
    }
    return 0;
}