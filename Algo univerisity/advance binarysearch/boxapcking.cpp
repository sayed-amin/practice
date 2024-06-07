#include <bits/stdc++.h>
using namespace std;
#define int long long

int predicate(int mid, int w, int h, int n)
{
    int total_boxes_bywidth = mid / w;
    int total_boxes_byheight = mid / h;
    int total_boxes = total_boxes_byheight * total_boxes_bywidth;
    if (total_boxes < n)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
int32_t main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int w, h, n;
        cin >> w >> h >> n;
        int low = 0, high = 1;
        while (predicate(high, w, h, n) == 0)
        {
            high *= 2;
        }
        while (low + 1 < high)
        {
            int mid = low + (high - low) / 2;
            if (predicate(mid, w, h, n) == 0)
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