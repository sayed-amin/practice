/*
Distinct_character_quiries.cpp
19 July 2022
Tue 04:33
storing distinct char in set
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N = 1e6 + 10;
string s;
set<char> tree[N];
void build(int node, int start, int end)
{
    if (start == end)
    {
        tree[node].insert(s[start]);
    }
    else
    {
        int mid = (start + end) / 2;
        build(2 * node, start, mid);
        build(2 * node + 1, mid + 1, end);
        tree[node].insert(tree[2 * node].begin(), tree[2 * node].end());
        tree[node].insert(tree[2 * node + 1].begin(), tree[2 * node + 1].end());
    }
}
set<char> query(int node, int l, int r, int a, int b)
{
    set<char> left, right, result;

    // If the range is out of the bounds
    // of this segment
    if (b < l || a > r)
        return result;

    // If the range lies in this segment
    if (a <= l && r <= b)
        return tree[node];

    // Else query for the right and left
    // leaf node of this subtree
    // and insert them into the set
    left = query(2 * node, l, (l + r) / 2, a, b);
    result.insert(left.begin(), left.end());

    right = query(1 + 2 * node, 1 + (l + r) / 2, r, a, b);
    result.insert(right.begin(), right.end());

    // Return the result
    return result;
}
void update(int node, int start, int end, int pos, char value)
{
    if (start == end)
    {
        tree[node].clear();
        tree[node].insert(value);
    }
    else
    {
        tree[node].clear();
        int mid = (start + end) / 2;
        if (pos <= mid)
            update(2 * node, start, mid, pos, value);
        else
            update(2 * node + 1, mid + 1, end, pos, value);
        tree[node].insert(tree[2 * node].begin(), tree[2 * node].end());
        tree[node].insert(tree[2 * node + 1].begin(), tree[2 * node + 1].end());
    }
}
void getDistinct(int l, int r, int n)
{
    // Query for the range set
    set<char> ans = query(1, 0, n, l, r);

    cout << ans.size() << endl;
}
void solve()
{

    cin >> s;
    build(1, 0, s.size() - 1);
    int q;
    cin >> q;
    while (q--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int pos;
            cin >> pos;
            char value;
            cin >> value;
            update(1, 0, s.size() - 1, pos - 1, value);
        }
        else
        {
            // cout << 1;
            int l, r;
            cin >> l >> r;
            l--, r--;
            getDistinct(l, r, s.size() - 1);
        }
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    //   cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}