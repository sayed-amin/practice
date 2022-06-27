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
const int N = 1e6 + 10;
vector<bool> isprime(N, 1);
vector<int> ans(N, 0);
void solve()
{
    int n;
    cin >> n;
    cout << ans[n] << endl;
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
        if (isprime[i] == true)
            for (int j = i * 2; j < N; j += i)
                isprime[j] = false;
    }
    int count = 0;
    for (int i = 5; i < N; i++)
    {
        if (isprime[i] and isprime[i - 2])
            count++;
        ans[i] = count;
    }
    while (t--)
    {
        solve();
    }
    return 0;
}