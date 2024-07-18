class Solution
{
public:
    // Function to find the length of longest common subsequence in two strings
    int solve(int n, int m, string str1, string str2, vector<vector<int>> &dp) // recursive approach
    {
        if (n == 0 || m == 0)
        {
            return 0;
        }
        if (dp[n][m] != -1)
        {
            return dp[n][m];
        }
        if (str1[n - 1] == str2[m - 1])
        {
            return dp[n][m] = 1 + solve(n - 1, m - 1, str1, str2, dp);
        }
        else
        {
            return dp[n][m] = max(solve(n - 1, m, str1, str2, dp), solve(n, m - 1, str1, str2, dp));
        }
    }
    int lcs(int n, int m, string str1, string str2)
    {
        // your code here
        vector<vector<int>> dp(n + 1, vector<int>(m + 1));
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= m; j++)
            {
                if (i == 0 || j == 0)
                {
                    dp[i][j] = 0;
                }
            }
        }
        for (int i = 1; i <= n; i++) // tabulation approach
        {
            for (int j = 1; j <= m; j++)
            {
                if (str1[i - 1] == str2[j - 1])
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[n][m];
    }
};
