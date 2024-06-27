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

vector<int> majorityElement(vector<int> &nums)
{
    unordered_map<int, int> mpp;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        mpp[nums[i]]++;
    }
    int freq = floor(n / 3);
    vector<int> ans;
    for (auto it : mpp)
    {
        if (it.second > freq)
        {
            ans.push_back(it.first);
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
    vector<int> ans = majorityElement(nums);
    for (auto it : ans)
    {
        cout << it << " ";
    }
    cout << endl;
}