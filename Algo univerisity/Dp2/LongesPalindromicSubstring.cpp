class Solution
{
public:
    string longestPalindrome(string s)
    {

        // dp[][] i -> j substring whether it is a palindrome or not
        vector<vector<bool>> dp(s.size() + 1, vector<bool>(s.size() + 1, false));
        int maxlenght = 1, sidx = 0;
        for (int i = 0; i < s.size(); i++)
        {
            dp[i][i] = true;
        }
        for (int i = 1; i < s.size(); i++)
        {

            dp[i][i - 1] = s[i] == s[i - 1];
        }

        for (int j = 1; j < s.size(); j++)
        {

            for (int i = 0; i + j < s.size(); i++)
            {

                int left = i, right = j + i;

                if (dp[left + 1][right - 1] && s[left] == s[right])
                {
                    dp[left][right] = true;
                    sidx = i;
                    maxlenght = j + 1;
                }
            }
        }
        // cout<<maxlenght;
        return s.substr(sidx, maxlenght);
    }
};