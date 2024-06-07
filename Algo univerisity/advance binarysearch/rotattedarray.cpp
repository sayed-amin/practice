#include <bits/stdc++.h>
using namespace std;

int predicate(int mid, vector<int> &a)
{
    if (a[mid] <= a[a.size() - 1])
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int main()
{

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int low = -1, high = n;
    while (low + 1 < high)
    {
        int mid = (high + low) / 2;
        if (predicate(mid, a) == 0)
        {
            low = mid;
        }
        else
        {
            high = mid;
        }
    }
    cout << a[high] << endl;

    return 0;
}