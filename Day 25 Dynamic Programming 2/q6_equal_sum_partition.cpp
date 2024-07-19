class Solution
{
public:
    bool subset(vector<int> &nums, int sum, int n, vector<vector<int>> &dp)
    {
        if (sum == 0)
        {
            return true;
        }
        if (n == 0 && sum != 0)
        {
            return false;
        }
        if (dp[n][sum] != -1)
        {
            return dp[n][sum];
        }
        if (nums[n - 1] <= sum) // can pick
        {
            return dp[n][sum] = subset(nums, sum - nums[n - 1], n - 1, dp) || subset(nums, sum, n - 1, dp);
        } // cannot pick
        else if (nums[n - 1] > sum)
        {
            return dp[n][sum] = subset(nums, sum, n - 1, dp);
        }
        return dp[n][sum];
    }
    bool canPartition(vector<int> &nums)
    {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
        }
        vector<vector<int>> dp(nums.size() + 1, vector<int>(sum + 1, -1));
        // if the sum turns out to be an odd number, it cannot into two equal halves
        if (sum % 2 != 0)
        {
            return false;
        }
        else
        {
            return subset(nums, sum / 2, nums.size(), dp);
        }
    }
};