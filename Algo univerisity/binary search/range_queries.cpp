
#include <bits/stdc++.h>
using namespace std;
int predicate(int mid, vector<int> &vec, int target)
{
    if (vec[mid] < target)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
int predicate2(int mid, vector<int> &vec, int target)
{
    if (vec[mid] <= target)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
int main()
{

    int n, q;
    cin >> n >> q;
    vector<int> vec(n);
    for (int i = 0; i < n; i++)
        cin >> vec[i];
    sort(vec.begin(), vec.end());
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        int low = -1, high = n;
        while (low + 1 < high)
        {
            int mid = (low + high) / 2;
            if (predicate(mid, vec, l) == 0)
            {
                low = mid;
            }
            else
            {
                high = mid;
            }
        }

        int low_index = high;
        //  cout << low_index++ << endl;
        low = -1, high = n;
        while (low + 1 < high)
        {
            int mid = (low + high) / 2;
            if (predicate2(mid, vec, r) == 0)
            {
                low = mid;
            }
            else
            {
                high = mid;
            }
        }
        int high_index = high;
        // cout << high_index++ << endl;
        cout << high_index - low_index << " ";
    }
    return 0;
}