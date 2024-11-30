#include <bits/stdc++.h>
using namespace std;

bool findTarget(int idx, int target, vector<int> &choclates)
{
    if (idx < 0 || target < 0)
    {
        return false;
    }
    if (target == 0)
    {
        return true;
    }
    int ans = findTarget(idx - 1, target, choclates);
    ans |= findTarget(idx - 1, target - choclates[idx], choclates);
    return ans;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> choclates(n);
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> choclates[i];
            ans += choclates[i];
        }
        if (ans & 1)
        {
            cout << "NO" << endl;
            continue;
        }
        cout << findTarget(n - 1, ans / 2, choclates) << endl;
    }
    return 0;
}