class Solution
{
public:
    int dp[1001][1001];
    // checking if they are palindrome
    int solve(string &s, int i, int j)
    {
        if (i >= j)
        {
            return 1;
        }
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }
        if (s[i] == s[j])
        {
            return dp[i][j] = solve(s, i + 1, j - 1);
        }
        // else return false
        return dp[i][j] = 0;
    }
    string longestPalindrome(string s)
    {
        memset(dp, -1, sizeof(dp));
        // checking for every possible substring
        int maxLen = INT_MIN;
        int starting_point = -1;
        for (int i = 0; i < s.length(); i++)
        {
            for (int j = i; j < s.length(); j++)
            {
                if (solve(s, i, j) == true)
                {
                    // if greater than current max length, update
                    if (j - i + 1 > maxLen)
                    {
                        maxLen = j - i + 1;
                        starting_point = i;
                    }
                }
            }
        }
        return s.substr(starting_point, maxLen);
    }
};