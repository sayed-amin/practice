/*
Hacker.cpp
26 June 2022
Sun 12:10
https://www.hackerearth.com/practice/math/number-theory/basic-number-theory-2/practice-problems/algorithm/hacker-with-prime-bebe28ac/
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N = 1e6 + 10;
vector<int> hp(N, 0);
vector<int> hs(N, 0);
vector<int> canremove(N, 0);
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
int32_t main()
{
    for (int i = 2; i < N; i++)
    {
        if (hp[i] == 0)
        {
            for (int j = i; j < N; j += i)
                hp[j] = i;
        }
    }
    int n, q;
    cin >> n >> q;
    // cout << n << q << endl;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        hs[x] = 1;
    }
    for (int i = 2; i < N; i++)
    {
        if (hs[i])
        {
            for (int j = i; j < N; j *= i)
                canremove[j] = 1;
        }
    }
    while (q--)
    {
        int x;
        cin >> x;
        vector<int> pf = distinct_prime(x);
        bool ispossible = false;
        for (int i = 0; i < pf.size(); i++)
        {
            for (int j = i; j < pf.size(); j++)
            {

                int product = pf[i] * pf[j];
                if (i == j and x % product != 0)
                    continue;
                int toremove = x / product;
                if (canremove[toremove] == 1 || toremove == 1)
                {
                    ispossible = true;
                    break;
                }
            }
            if (ispossible)
                break;
        }
        if (ispossible)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
