
// mcm ka variation hai

class Solution
{
public:
    int solve(vector<int> &cuts, int start, int end, vector<vector<int>> &dp)
    {
        if (end - start < 2)
        {
            return 0;
        }
        if (dp[start][end] != -1)
        {
            return dp[start][end];
        }
        int ans = INT_MAX;
        for (int ind = start + 1; ind < end; ind++)
        {
            int temp = (cuts[end] - cuts[start]) + solve(cuts, start, ind, dp) + solve(cuts, ind, end, dp);
            ans = min(ans, temp);
        }
        return dp[start][end] = ans;
    }
    int minCost(int n, vector<int> &cuts)
    {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        vector<vector<int>> dp(cuts.size(), vector<int>(cuts.size(), -1));
        return solve(cuts, 0, cuts.size() - 1, dp);
    }
};