#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 1e5 + 5;

map<int, int> par[N], Size[N];

// Find operation with path compression
int find(int v, int f)
{
    if (par[f][v] != v)
    {
        par[f][v] = find(par[f][v], f); // Path compression
    }
    return par[f][v];
}

// Union operation with union by size
bool Union(int a, int b, int f)
{
    a = find(a, f);
    b = find(b, f);

    if (a == b)
        return true; // They are already in the same set

    // Join smaller tree under the bigger one
    if (Size[f][a] < Size[f][b])
    {
        swap(a, b);
    }
    par[f][b] = a; // Joining b under a
    Size[f][a] += Size[f][b];
    return false; // No redundant edge
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    int ans = 0;

    // Process each road
    for (int i = 0; i < m; i++)
    {
        int num1, num2, f;
        cin >> num1 >> num2 >> f;

        // Initialize Union-Find structure for the family if not done yet
        if (par[f].count(num1) == 0)
        {
            par[f][num1] = num1;
            Size[f][num1] = 1;
        }
        if (par[f].count(num2) == 0)
        {
            par[f][num2] = num2;
            Size[f][num2] = 1;
        }

        // Check if the edge is redundant
        if (Union(num1, num2, f))
        {
            ans++; // Increment count of redundant edges
        }
    }

    cout << ans << endl;

    return 0;
}
