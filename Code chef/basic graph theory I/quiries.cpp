#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int par[N];
int s[N];
int distinct;

void make(int v)
{
    par[v] = v;
    s[v] = 1;
}
int find(int v)
{
    if (v == par[v])
        return v;
    // path compression
    return par[v] = find(par[v]);
}
void Union(int a, int b)
{
    a = find(a);
    b = find(b);
    if (a != b)
    { // union by size
        if (s[a] < s[b])
            swap(a, b);
        par[b] = a;
        s[a] += s[b];
        distinct--;
    }
}
int main()
{
    int n, q;
    cin >> n >> q;
    distinct = n;

    for (int i = 1; i <= n; i++)
        make(i);
    while (q--)
    {
        int m;
        cin >> m;

        if (m == 1)
        {
            int a, b;
            cin >> a >> b;
            Union(a, b);
        }
        else if (m == 2)
        {
            int a, b;
            cin >> a >> b;

            a = find(a);
            b = find(b);
            if (a == b)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
        else
            cout << distinct << endl;
    }

    return 0;
}
