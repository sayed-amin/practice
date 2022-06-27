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
const int N = 1e4 + 10;
vector<bool> isprime(N, 0);
vector<int> prime;
vector<int> ct(N, 0);
void solve()
{
    int n;
    cin >> n;
    cout << ct[n] << endl;
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
            isprime[i] = i;
            prime.push_back(i);
            for (int j = 2 * i; j < N; j += i)
            {
                isprime[j] = 1;
            }
        }
    }
    for (auto i = prime.begin(); i != prime.end(); i++)
    {
        for (auto j = prime.begin(); j != prime.end(); j++)
        {
            int temp = (*i) + (2 * (*j));
            // int temp2 = (*j) + (2 * (*i));
            //  cout << temp << endl;

            if (temp < N)
                ct[temp]++;
            else
                break;
        }
    }
    while (t--)
    {
        solve();
    }
    return 0;
}