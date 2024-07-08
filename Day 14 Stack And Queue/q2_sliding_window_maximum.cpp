// brute force - gives tle
class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        vector<int> ans;
        for (int i = 0; i < (nums.size() - k + 1); i++)
        {
            long long maxi = nums[i];
            for (int j = i + 1; j <= (i + k - 1); j++)
            {
                if (nums[j] > maxi)
                {
                    maxi = nums[j];
                }
            }
            ans.push_back(maxi);
        }
        return ans;
    }
};

// optimized approach- monotonic queue using deque

class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        vector<int> ans;
        deque<int> dq;
        for (int i = 0; i < nums.size(); i++)
        {
            // removing out of bound elements if present
            if (!dq.empty() && dq.front() == i - k)
            {
                dq.pop_front();
            }
            // if curr element is greater than the element at the back position of deque, pop it.
            // because we are storing in monotonically decreasing order,and so that the max element
            // could be found at the front position
            while (!dq.empty() && nums[dq.back()] < nums[i])
            {
                dq.pop_back();
            }
            dq.push_back(i);
            // if we have reached the window
            if (i >= k - 1)
            {
                ans.push_back(nums[dq.front()]);
            }
        }
        return ans;
    }
};