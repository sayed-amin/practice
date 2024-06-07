/*
firstand lastindex.cpp
05 May 2024
Sun 11:06

*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int predicate(int mid, vector<int> &vec, int target)
{
    if (vec[mid] < target)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
int predicate2(int mid, vector<int> &vec, int target)
{
    if (vec[mid] <= target)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> vec(n);
    for (int i = 0; i < n; i++)
    {
        cin >> vec[i];
    }
    while (q--)
    {
        int target;
        cin >> target;
        int low = -1, high = n;
        while (low + 1 < high)
        {
            int mid = (low + high) / 2;
            if (predicate(mid, vec, target) == 0)
            {
                low = mid;
            }
            else
            {
                high = mid;
            }
        }
        if (high < n and vec[high] == target)
        {
            cout << high << " ";
        }
        else
        {
            cout << -1 << " ";
        }
        low = -1, high = n;
        while (low + 1 < high)
        {
            int mid = (low + high) / 2;
            if (predicate2(mid, vec, target) == 0)
            {
                low = mid;
            }
            else
            {
                high = mid;
            }
        }
        high--;
        if (high < n and vec[high] == target)
        {
            cout << high << endl;
        }
        else
        {
            cout << -1 << endl;
        }
    }
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