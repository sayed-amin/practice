#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int minTotalInstability(vector<int> &heights)
{
    int X = heights.size() / 2;
    sort(heights.begin(), heights.end());
    int minInstability = INT_MAX;

    // Try every pair of people to be in the single-seaters
    for (int i = 0; i < 2 * X; ++i)
    {
        for (int j = i + 1; j < 2 * X; ++j)
        {
            vector<int> remaining;
            for (int k = 0; k < 2 * X; ++k)
            {
                if (k != i && k != j)
                {
                    remaining.push_back(heights[k]);
                }
            }
            int instability = 0;
            for (int k = 0; k < remaining.size(); k += 2)
            {
                instability += abs(remaining[k] - remaining[k + 1]);
            }
            minInstability = min(minInstability, instability);
        }
    }
    return minInstability;
}

int main()
{
    int X;
    cin >> X;
    vector<int> heights(2 * X);
    for (int i = 0; i < 2 * X; ++i)
    {
        cin >> heights[i];
    }
    cout << minTotalInstability(heights) << endl;
    return 0;
}
