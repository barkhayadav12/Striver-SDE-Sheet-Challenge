#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <stack>
#include <utility>
#include <queue>
#include <unordered_map>
#include <math.h>
using namespace std;

int majorityElement(vector<int> &nums)
{
    int num = ceil(nums.size() / 2);
    unordered_map<int, int> mpp;
    int ans = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        mpp[nums[i]]++;
    }
    for (auto i : mpp)
    {
        if (i.second > num)
        {
            ans = i.first;
            break;
        }
    }
    return ans;
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
    cout << majorityElement(nums) << endl;
}