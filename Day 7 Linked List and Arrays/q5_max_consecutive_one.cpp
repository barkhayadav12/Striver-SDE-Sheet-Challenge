class Solution
{
public:
    int findMaxConsecutiveOnes(vector<int> &nums)
    {
        int cnt = 0;
        int maxCount = 0;
        for (int i = 0; i <= nums.size() - 1; i++)
        {
            if (nums[i] == 1)
            {
                cnt++;
                maxCount = max(cnt, maxCount);
            }
            else
            {
                cnt = 0;
            }
        }
        return maxCount;
    }
};