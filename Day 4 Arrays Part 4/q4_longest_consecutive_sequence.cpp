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

int longestConsecutiveSequence(vector<int> &nums, int n)
{
    if (n == 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return 1;
    }
    sort(nums.begin(), nums.end());
    int cnt = 1;
    int maxi = 1;
    for (int i = 1; i < n; i++)
    {
        // because duplicate values bhi present ho skte hai
        if (nums[i] - nums[i - 1] == 0)
        {
            continue;
        }
        else if (nums[i] - nums[i - 1] == 1)
        {
            cnt++;
        }
        else
        {
            cnt = 1;
        }
        maxi = max(cnt, maxi);
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
    cout << longestConsecutiveSequence(nums, n) << endl;
}