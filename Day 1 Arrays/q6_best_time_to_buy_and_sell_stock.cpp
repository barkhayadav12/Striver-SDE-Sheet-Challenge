#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

int maxProfit(vector<int> &nums)
{
    int mini = nums[0];
    int maxi = 0;
    for (int i = 1; i < nums.size(); i++)
    {
        mini = min(nums[i], mini);
        maxi = max(maxi, nums[i] - mini);
    }
    return maxi;
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
    cout << maxProfit(nums) << endl;
}