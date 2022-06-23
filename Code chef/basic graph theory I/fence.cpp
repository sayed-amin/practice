// bfs used
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
// valid function to check point valid or not
bool isvalid(int x, int y, int r, int c)
{
    if (x < 0 || y < 0 || x >= r || y >= c)
        return false;
    return true;
}
int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int r, c, n;
    const int a[] = {1, -1, 0, 0};
    const int s[] = {0, 0, 1, -1};
    map<pair<int, int>, bool> vis;
    cin >> r >> c >> n;
    set<pair<int, int>> g;

    int x, y;
    for (int i = 1; i <= n; i++)
    {
        cin >> x >> y;
        pair<int, int> p = make_pair(x - 1, y - 1);
        g.insert(p);
        vis[p] = false;

        // cout << vis[p] << endl;
    }
    x = 0;
    y = 0;
    queue<pair<int, int>> q;

    for (auto l = g.begin(); l != g.end(); l++)
    {
        pair<int, int> p = make_pair((*l).first, (*l).second);
        //   cout << (*l).first << " " << (*l).second << endl;

        if (vis[p])
            continue;
        if (!vis[p])
        {
            q.push(p);
            vis[p] = true;
        }
        x = 0;
        while (!q.empty())
        {
            n = 4;
            pair<int, int> temp = q.front();
            q.pop();
            int k = temp.first;
            int l = temp.second;
            for (int t = 0; t < 4; t++)
            {
                temp.first = k + a[t];
                temp.second = l + s[t];
                pair<int, int> b = make_pair(temp.first, temp.second);
                if (isvalid(temp.first, temp.second, r, c))
                {

                    // cout << k << " " << l << endl;
                    if (vis.find(b) != vis.end())
                    {
                        n--;
                        if (!vis[b])
                            q.push(b);

                        vis[b] = 1;
                    }
                }
            }
            x += n;
        } // enfwhile
        // cout << x << endl;
        y = max(x, y);
    }

    cout << y << endl;
    return 0;
}