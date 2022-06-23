// leetcode heap problem no 4
#include <bits/stdc++.h>
using namespace std;
#define int long long
class Solution
{
public:
    int furthestBuilding(vector<int> &heights, int bricks, int ladders)
    {
        int j = 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        while (j + 1 < heights.size() and pq.size < l)
        {
            if (heights[j + 1] > heights[j])
            {
                int temp = heights[j + 1] - heights[j];
                pq.push(temp);
            }
            j++
        }
        for (int i = 0; i < heights.size() - 1; i++)
        {
            if (heights[i] >= heights[i + 1])
            {
                j = i;
                continue;
            }
            else
            {
                int top = pq.top();
                int diff = heights[i + 1] - heights[i];
                if (!pq.empty() and top < diff)
                {
                    if (bricks > top)
                    {
                        bricks -= top;
                        j = i;
                        pq.pop();
                        pq.push(diff);
                    }
                    else
                        break;
                }
            }
        }
        return j;
    }
};
void solve()
{
    Solution a;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}