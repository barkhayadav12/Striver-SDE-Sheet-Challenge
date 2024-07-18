class Solution
{
public:
    int solve(int i, int j, int arr[], vector<vector<int>> &dp)
    {
        if (i >= j)
        {
            return 0;
        }
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }
        int ans = INT_MAX;
        for (int k = i; k < j; k++)
        {
            int temp = solve(i, k, arr, dp) + solve(k + 1, j, arr, dp) + (arr[i - 1] * arr[k] * arr[j]);
            ans = min(temp, ans);
        }
        return dp[i][j] = ans;
    }
    int matrixMultiplication(int N, int arr[])
    {
        // code here
        int i = 1;
        int j = N - 1;
        vector<vector<int>> dp(N, vector<int>(N, -1));
        return solve(i, j, arr, dp);
    }
};