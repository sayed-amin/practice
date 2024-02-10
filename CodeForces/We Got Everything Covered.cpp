#include <iostream>
#include <string>

using namespace std;

string solve(int n, int k)
{
    if (n == 1)
    {
        string s(k, 'a');
        return s;
    }

    // Base cases:
    if (k == 1)
    {
        string s(n, 'a');
        return s;
    }
    if (n == 2)
    {
        string s(2 * k - 1, 'a');
        s[k - 1] = 'b';
        return s;
    }

    // Recursive approach:
    string s = solve(n - 1, k);
    string t = solve(n - 1, k - 1);
    char nextChar = 'a' + min(k - 1, n - 1); // Choose the appropriate character to insert

    // Interleave s and t, inserting nextChar between each character:
    string result;
    for (int i = 0; i < s.length(); ++i)
    {
        result += s[i];
        result += nextChar;
    }
    result += t;

    return result;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;

        string answer = solve(n, k);
        cout << answer << endl;
    }

    return 0;
}
