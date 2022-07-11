/*
merge_sort_array.cpp
03 July 2022
Sun 16:06
merge sort easy
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    vector<int> temp = nums1;
    nums1.clear();
    int i = 0;
    int j = 0;
    while (i < n and j < m)
    {
        if (temp[i] < nums2[j])
        {
            nums1.push_back(temp[i]);
            i++;
        }
        else if (temp[i] > nums2[j])
        {
            nums1.push_back(nums2[j]);
            j++;
        }
    }
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