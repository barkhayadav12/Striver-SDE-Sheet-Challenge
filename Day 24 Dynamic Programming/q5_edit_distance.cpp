class Solution
{
public:
    int fn(string a, string b, int n, int m, vector<vector<int>> &dp)
    {
        if (n == 0)
        {
            return dp[n][m] = m;
        }
        if (m == 0)
        {
            return dp[n][m] = n;
        }
        if (dp[n][m] != -1)
        {
            return dp[n][m];
        }
        if (a[n - 1] == b[m - 1])
        {
            return dp[n][m] = fn(a, b, n - 1, m - 1, dp);
        }
        else
        {
            int insert = fn(a, b, n, m - 1, dp);
            int del = fn(a, b, n - 1, m, dp);
            int replace = fn(a, b, n - 1, m - 1, dp);
            return dp[n][m] = 1 + min(insert, min(del, replace));
        }
    }
    int minDistance(string word1, string word2)
    {
        int n = word1.length();
        int m = word2.length();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        return fn(word1, word2, n, m, dp);
    }
};