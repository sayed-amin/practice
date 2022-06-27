/*
PTUPLES.cpp
25 June 2022
Sat 22:15
number theory
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N = 1e5 + 10;
vector<int> isprime(N, 0);
void solve()
{
    int a, b;
    cin >> a >> b;
    int k;
    cin >> k;
    int ans = 0;
    for (int i = a; i <= b; i++)
    {
        if (isprime[i] == k)
            ans++;
    }
    cout << ans << endl;
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
            for (int j = i * 2; j < N; j += i)
                isprime[j]++;
        }
    }
    while (t--)
    {
        solve();
    }
    return 0;
}