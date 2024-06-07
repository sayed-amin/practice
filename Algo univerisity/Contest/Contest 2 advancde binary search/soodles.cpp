/*
soodles.cpp
18 May 2024
Sat 17:26
Solution using Two Pointer
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int minCopiesToFormString(const string &A, const string &B)
{
    int n = A.size();
    int m = B.size();

    // Create a map of characters to their positions in B
    unordered_map<char, vector<int>> charPosMap;
    for (int i = 0; i < m; ++i)
    {
        charPosMap[B[i]].push_back(i);
    }

    int copies = 1; // At least one copy of B is needed
    int bIndex = 0; // Start from the beginning of B

    for (int i = 0; i < n; ++i)
    {
        char currentChar = A[i];

        // If the current character of A is not in B at all, it's impossible to form A
        if (charPosMap.find(currentChar) == charPosMap.end())
        {
            return -1;
        }

        // Binary search for the next position in B where currentChar appears
        auto &positions = charPosMap[currentChar];
        auto it = lower_bound(positions.begin(), positions.end(), bIndex);

        if (it == positions.end())
        {
            // Need a new copy of B because we can't find currentChar in the remaining part of B
            copies++;
            bIndex = 0;
            it = lower_bound(positions.begin(), positions.end(), bIndex);
        }

        // Move to the next character position in B
        bIndex = *it + 1;
    }

    return copies;
}

void solve()
{
    string A, B;
    cin >> A >> B;

    int result = minCopiesToFormString(A, B);
    cout << result << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int testcase = 1;
    cin >> testcase;
    while (testcase--)
    {
        solve();
    }
    return 0;
}