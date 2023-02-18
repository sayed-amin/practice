/*
graph_maxtrix_problem.cpp
18 February 2023
Sat 19:47
how to approach a graph matrix problems
https://leetcode.com/problems/longest-increasing-path-in-a-matrix/
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void dfs(int i, int j, int intialcolour, int newcolour, vector<vector<int>> &image)
{
    int n = image.size();
    int m = image[0].size();
    if (i < 0 || j < 0)
        return;
    if (i >= n || j >= m)
        return;
    if (image[i][j] != intialcolour)
        return;
    image[i][j] = newcolour;
    dfs(i + 1, j, intialcolour, newcolour, image);
    dfs(i - 1, j, intialcolour, newcolour, image);
    dfs(i, j + 1, intialcolour, newcolour, image);
    dfs(i, j - 1, intialcolour, newcolour, image);
}
vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newcolour)
{
    int intialcolour = image[sr][sc];
    if (intialcolour != newcolour)
        dfs(sr, sc, intialcolour, newcolour, image);
    return image;
}
void solve()
{
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