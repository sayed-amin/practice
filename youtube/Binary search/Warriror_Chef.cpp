/*
Warriror_Chef.cpp
23 January 2024
Tue 09:28

*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

bool is_defeated(vector<int> &v, int h, int mid)
{
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] <= mid)
        {
            continue;
        }
        else
        {
            if (v[i] < h)
            {
                h -= v[i];
            }
            else
                return false;
        }
    }
    return true;
}
void solve()
{
    int n, h;
    cin >> n >> h;
    vector<int> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    int low = 0;
    int high = *max_element(v.begin(), v.end());
    sort(v.begin(), v.end());
    // F F F F F T T T T
    while (high - low > 1)
    {
        int mid = low + (high - low) / 2;
        if (is_defeated(v, h, mid))
        {
            high = mid;
        }
        else
        {
            low = mid + 1;
        }
    }
    // cout << high << " " << low << endl;
    if (is_defeated(v, h, low))
        cout << low << endl;
    else
        cout << high << endl;
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