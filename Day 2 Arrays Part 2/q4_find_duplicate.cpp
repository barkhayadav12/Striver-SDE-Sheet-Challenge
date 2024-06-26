#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <stack>
#include <utility>
#include <queue>
#include <unordered_map>

using namespace std;

int findDuplicate(vector<int> &nums)
{
    unordered_map<int, int> mpp;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        mpp[nums[i]]++;
    }
    for (auto it : mpp)
    {
        if (it.second > 1)
        {
            return it.first;
        }
    }
    return 1;
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n + 1);
    for (int i = 0; i < n + 1; i++)
    {
        cin >> nums[i];
    }
    cout << findDuplicate(nums) << endl;
}