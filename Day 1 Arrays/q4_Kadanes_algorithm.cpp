#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

int maxSubArray(vector<int> &nums)
{
    int sum = 0;
    int tot_sum = 0;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        sum += nums[i];
        if (sum > tot_sum)
        {
            tot_sum = sum;
        }
        if (sum < 0)
        {
            sum = 0;
        }
    }
    return tot_sum;
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    cout << maxSubArray(nums) << endl;
}