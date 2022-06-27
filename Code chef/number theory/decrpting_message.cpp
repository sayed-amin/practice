/*
decrpting_message.cpp
25 June 2022
Sat 16:24
https://www.hackerearth.com/practice/math/number-theory/basic-number-theory-2/practice-problems/algorithm/hacker-with-prime-bebe28ac/
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N = 1e6 + 10;
int a[N];
int hp[N];
vector<int> distinct_prime(int x)
{
    vector<int> ans;
    while (x > 1)
    {
        int pf = hp[x];
        while (x % pf == 0)
            x /= pf;
        ans.push_back(pf);
    }
    return ans;
}
void solve()
{
    for (int i = 1; i < N; i++)
    {
        if (hp[i] == 0)
        {
            for (int j = i; j < N; j += i)
                hp[i] = j;
        }
    }
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    while (q--)
    {
        int x;
        cin >> x;
        vector<int> pf = distinct_prime(x);
        for (int i = 0; i < pf.size(); i++)
        {

            for (int j = i; j < pf.size(); j++)
            {
                int product = pf[i] * pf[j];
                if (i == j and)
            }
        }
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}