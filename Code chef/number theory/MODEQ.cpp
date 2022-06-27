
/*
NUMFACT.cpp
26 June 2022
Sun 05:31
prime factorization
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N = 5e5 + 10;
vector<bool> isprime(N, 1);
vector<vector<int>> divisor(N);
vector<int> ct(N, 0);
void solve()
{
    int n, m, b;
    cin >> n >> m;
    int ans = 0;
    for (b = 2; b <= n; b++)
    {
        int x = (m - (m % b));
        if (x > 0)
            ans += lower_bound(divisor[x].begin(), divisor[x].end(), b) - divisor[x].begin();
        else
            ans += (b - 1);
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
    for (int i = 1; i < N; i++)
    {

        for (int j = i; j < N; j += i)
        {

            divisor[j].push_back(i);
        }
    }

    while (t--)
    {
        solve();
    }
    return 0;
}