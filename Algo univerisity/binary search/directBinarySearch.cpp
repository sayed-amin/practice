#include <bits/stdc++.h>
using namespace std;
int predicate(int mid, int target, vector<int> &vec)
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
int main()
{

    int n, q;
    cin >> n >> q;
    vector<int> vec(n);
    for (int i = 0; i < n; i++)
    {
        cin >> vec[i];
    }
    while (q--)
    {
        int target;
        cin >> target;
        int low = -1, high = n;
        while (low + 1 < high)
        {
            int mid = (low + high) / 2;
            if (predicate(mid, target, vec) == 0)
            {
                low = mid;
            }
            else
            {
                high = mid;
            }
        }
        cout << high << endl;
    }

    return 0;
}