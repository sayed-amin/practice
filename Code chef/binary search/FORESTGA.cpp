// binary serach
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 1;
int No_of_trees, wood_needed, height_to_cut;
vector<pair<int, int>> tree_height_rate;
bool issufficient(int months)
{
    int wood_gather = 0;
    for (int i = 0; i < No_of_trees; i++)
    {

        if (months >= ((height_to_cut - tree_height_rate[i].first + tree_height_rate[i].second - 1) / tree_height_rate[i].second))
        {
            wood_gather += tree_height_rate[i].first;
            if (wood_gather >= wood_needed)
                return true;
            wood_gather += months * tree_height_rate[i].second;
            if (wood_gather >= wood_needed)
                return true;
        }
        if (wood_gather >= wood_needed)
            return true;
    }
    return wood_gather >= wood_needed;
}
void solve()
{
    cin >> No_of_trees >> wood_needed >> height_to_cut;
    tree_height_rate.resize(No_of_trees);
    for (int i = 0; i < No_of_trees; i++)
        cin >> tree_height_rate[i].first >> tree_height_rate[i].second;
    int low = 0;
    int mid, high = 1e18 + 1;
    int ans = 0;
    while (high - low > 1)
    {
        mid = low + (high - low) / 2;
        if (issufficient(mid))
        {

            high = mid;
        }
        else
            low = mid + 1;
    }
    // cout << ans << endl;
    if (issufficient(high))
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
    // cin>>t;
    while (t--)
    {
        solve();
    }
    return 0;
}