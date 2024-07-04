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

// print all the subsequences

void printSubsequence(vector<int> &nums, int ind, vector<int> &v)
{
    if (ind == nums.size())
    {
        for (auto it : v)
        {
            cout << it << " ";
        }
        cout << endl;
        return;
    }

    // pick

    v.push_back(nums[ind]);
    printSubsequence(nums, ind + 1, v);

    // don't pick

    v.pop_back();
    printSubsequence(nums, ind + 1, v);
}

// count number of subsequence with sum k

void countSubsequenceWithSumK(vector<int> &nums, int &cnt, int ind, int k, vector<int> &v)
{
    if (ind == nums.size())
    {
        int sum = 0;
        for (auto it : v)
        {
            sum += it;
        }
        if (sum == k)
        {
            cnt++;
        }
        return;
    }
    // pick

    v.push_back(nums[ind]);
    countSubsequenceWithSumK(nums, cnt, ind + 1, k, v);

    // don't pick

    v.pop_back();
    countSubsequenceWithSumK(nums, cnt, ind + 1, k, v);
}

// combination sum 1

void combinationSum1(vector<int> &nums, int target, int ind, vector<int> &v)
{
    if (target < 0)
    {
        return;
    }
    if (target == 0)
    {
        for (auto it : v)
        {
            cout << it << " ";
        }
        cout << endl;
        return;
    }
    for (int i = ind; i < nums.size(); i++)
    {
        v.push_back(nums[i]);
        combinationSum1(nums, target - nums[i], i, v); // coz duplicates are allowed
        v.pop_back();
    }
}

// combination Sum 2

void combinationSum2(vector<int> &nums, int ind, int target, vector<int> &v)
{
    if (target < 0)
    {
        return;
    }
    if (target == 0)
    {
        for (auto it : v)
        {
            cout << it << " ";
        }
        cout << endl;
        return;
    }
    for (int i = ind; i < nums.size(); i++)
    {
        if (i != ind && nums[i] == nums[i - 1]) // to skip duplicates
        {
            continue;
        }
        v.push_back(nums[i]);
        combinationSum1(nums, target - nums[i], i + 1, v);
        v.pop_back();
    }
}

// subset sum 2

void subsetSum2(vector<int> &nums, int ind, vector<int> &v)
{
    for (auto it : v)
    {
        cout << it << " ";
    }
    cout << endl;
    for (int i = ind; i < nums.size(); i++)
    {
        if (i != ind && nums[i] == nums[i - 1]) // to skip duplicates
        {
            continue;
        }
        v.push_back(nums[i]);
        subsetSum2(nums, i + 1, v);
        v.pop_back();
    }
}

int main()
{
    vector<int> nums = {1, 2, 2};
    vector<int> v;
    // int cnt=0;
    // countSubsequenceWithSumK(nums,cnt,0,3,v);
    // cout<<cnt<<endl;
    // combinationSum2(nums, 0, 3, v);
    subsetSum2(nums, 0, v);
}