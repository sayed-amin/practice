#include <bits/stdc++.h>
using namespace std;

// Function to determine if the middle element is part of the rotated section
int predicate(int mid, vector<int> &a)
{
    if (a[mid] <= a.back())
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

    int low = 0, high = n - 1;

    // Edge case for when the array is not rotated at all
    if (a[low] <= a[high])
    {
        cout << a[low] << endl;
        return 0;
    }

    while (low < high)
    {
        int mid = (low + high) / 2;

        if (predicate(mid, a))
        {
            high = mid;
        }
        else
        {
            low = mid + 1;
        }
    }

    cout << a[low] << endl;

    return 0;
}
