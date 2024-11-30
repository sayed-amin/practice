#include <bits/stdc++.h>
using namespace std;
/*


*/
int heightCombination(int idx, int h, vector<int> &heights)
{
    if (h < 0 || idx < 0)
    {
        return 0;
    }
    if (h == 0)
    {
        return 1;
    }
    int ans = heightCombination(idx - 1, h, heights);

    ans += heightCombination(idx, h - heights[idx], heights);
    return ans;
}
int main()
{

    in t;
    cin >> t;
    while (t--)
    {
    }

    return 0;
}