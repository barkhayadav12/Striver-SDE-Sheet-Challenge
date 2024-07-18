class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        double pref = 1;
        int n = nums.size();
        double ans = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            pref *= nums[i];
            ans = max(ans, pref);
            if (pref == 0)
            {
                pref = 1;
            }
        }
        double suff = 1;
        for (int i = n - 1; i >= 0; i--)
        {
            suff *= nums[i];
            ans = max(ans, suff);
            if (suff == 0)
            {
                suff = 1;
            }
        }
        return ans;
    }
};