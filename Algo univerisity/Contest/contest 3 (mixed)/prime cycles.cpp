/*
prime cycles.cpp
22 June 2024
Sat 22:04

*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
bool is_prime(int num)
{
    if (num <= 1)
        return false;
    for (int i = 2; i * i <= num; i++)
    {
        if (num % i == 0)
            return false;
    }
    return true;
}

bool is_prime_cycle(const vector<int> &perm)
{
    int n = perm.size();
    for (int i = 0; i < n; i++)
    {
        if (!is_prime(perm[i] + perm[(i + 1) % n]))
        {
            return false;
        }
    }
    return true;
}

void generate_permutations(vector<int> &perm, int start, set<vector<int>> &unique_cycles)
{
    if (start == perm.size())
    {
        if (is_prime_cycle(perm))
        {

            vector<int> min_rotation = perm;
            int n = perm.size();
            for (int i = 1; i < n; i++)
            {
                vector<int> rotation(n);
                for (int j = 0; j < n; j++)
                {
                    rotation[j] = perm[(i + j) % n];
                }
                min_rotation = min(min_rotation, rotation);
            }
            unique_cycles.insert(min_rotation);
        }
        return;
    }
    for (int i = start; i < perm.size(); i++)
    {
        swap(perm[start], perm[i]);
        generate_permutations(perm, start + 1, unique_cycles);
        swap(perm[start], perm[i]); // backtrack
    }
}
void solve()
{
    int n;
    cin >> n;

    vector<int> perm(n);
    for (int i = 0; i < n; i++)
    {
        perm[i] = i + 1;
    }

    set<vector<int>> unique_cycles;
    generate_permutations(perm, 0, unique_cycles);

    cout << unique_cycles.size() << endl;
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