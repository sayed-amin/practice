/*
test.cpp
21 April 2024
Sun 14:14

*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void solve()
{
    int n;
    cin >> n;
    vector<int> vec(n);
    int first_positive_index = -1;
    for (int i = 0; i < n; i++)
    {
        cin >> vec[i];
        if (vec[i] >= 0 and first_positive_index == -1)
        {
            first_positive_index = i;
        }
    }
    int i = first_positive_index - 1, j = first_positive_index;
    if (first_positive_index == 0)
    {
        i = first_positive_index;
    }
    else if (first_positive_index == -1)
    {
        i = n - 1;
        j = n - 1;
    }
    // cout << i << " " << j << endl;
    while (i >= 0 and j < n)
    {
        int square1 = vec[i] * vec[i];
        int square2 = vec[j] * vec[j];
        if (square1 < square2)
        {
            cout << square1 << " ";
            i--;
        }
        else
        {
            cout << square2 << " ";
            j++;
        }
    }
    while (i >= 0)
    {
        cout << vec[i] * vec[i] << " ";
        i--;
    }
    while (j < n)
    {
        cout << vec[j] * vec[j] << " ";
        j++;
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