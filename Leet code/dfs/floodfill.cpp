/*
floodfill.cpp
29 June 2022
Wed 04:24

*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void dfs(int i, int j, int initial, int color, vector<vector<int>> &image)
{
    if (i < 0 || j < 0)
        return;
    if (i >= image.size() || j > image[0].size())
        return;
    image[i][j] = color;
    dfs(i - 1, j, initial, color, image);
    dfs(i + 1, j, initial, color, image);
    dfs(i, j - 1, initial, color, image);
    dfs(i, j + 1, initial, color, image);
}
vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
{
    int initial = image[sr][sc];
    if (initial != color)
        dfs(sr, sc, initial, color, image);
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