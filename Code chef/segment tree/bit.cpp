/*
bit.cpp
18 July 2022
Mon 12:39
segment tree
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

long long binpow(long long a, long long b)
{
    long long res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}
const int N = 1e6 + 10;
int tree[N], a[N];

void build(int node, int start, int end)
{
    if (start == end)
        tree[node] = a[start];
    else
    {
        int mid = (start + end) / 2;
        build(2 * node, start, mid);
        build(2 * node + 1, mid + 1, end);
        int t = log2(end - start + 1);
        if (t & 1)
            tree[node] = (tree[2 * node] | tree[2 * node + 1]);
        else
            tree[node] = (tree[2 * node] ^ tree[2 * node + 1]);
    }
}
void update(int node, int start, int end, int pos, int value)
{
    if (start == end)
        tree[node] = value;
    else
    {
        int mid = (start + end) / 2;
        if (pos <= mid)
        {
            update(2 * node, start, mid, pos, value);
        }
        else
        {
            update(2 * node + 1, mid + 1, end, pos, value);
        }
        int t = log2(end - start + 1);
        if (t & 1)
            tree[node] = tree[2 * node] | tree[2 * node + 1];
        else
            tree[node] = tree[2 * node] ^ tree[2 * node + 1];
    }
}
void solve()
{
    int n, m;
    cin >> n >> m;
    n = binpow(2, n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    build(1, 0, n - 1);
    while (m--)
    {
        int pos, value;
        cin >> pos >> value;
        pos--;
        update(1, 0, n - 1, pos, value);
        cout << tree[1] << endl;
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}