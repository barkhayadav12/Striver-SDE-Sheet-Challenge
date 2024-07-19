class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        int n = coins.size();
        int t[n + 1][amount + 1];
        memset(t, -1, sizeof(t));
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= amount; j++)
            {
                if (i == 0)
                {
                    t[i][j] = INT_MAX - 1;
                }
                if (j == 0)
                {
                    t[i][j] = 0;
                }
            }
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= amount; j++)
            {
                if (coins[i - 1] <= j)
                {
                    t[i][j] = min(t[i - 1][j], t[i][j - coins[i - 1]] + 1);
                }
                else if (coins[i - 1] > j)
                {
                    t[i][j] = t[i - 1][j];
                }
            }
        }
        if (t[n][amount] == INT_MAX - 1)
        {
            return -1;
        }
        return t[n][amount];
    }
};