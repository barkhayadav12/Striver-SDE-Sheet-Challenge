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

// printing all the subsequences

// arrays
void fn(vector<int> &nums, int ind, vector<int> &v)
{
    int n = nums.size();

    // base case

    if (ind == n)
    {
        for (auto it : v)
        {
            cout << it << " ";
        }
        cout << endl;
        return;
    }
    v.push_back(nums[ind]);

    // pick
    fn(nums, ind + 1, v);

    v.pop_back();

    // don't pick
    fn(nums, ind + 1, v);
}

// return the sum of all the subsets

void sumOfSubset(vector<int> &nums, vector<int> &v, vector<int> &ans, int ind)
{
    int n = nums.size();

    // base case
    if (ind == n)
    {
        int sum = 0;
        for (auto it : v)
        {
            sum += it;
        }
        ans.push_back(sum);
        return;
    }

    // pick
    v.push_back(nums[ind]);
    sumOfSubset(nums, v, ans, ind + 1);

    // doesn't pick

    v.pop_back();
    sumOfSubset(nums, v, ans, ind + 1);
}

// combination sum

void combinationSum(vector<int> &nums, int target, int sum, vector<int> &v, int ind, vector<vector<int>> &ans)
{
    int n = nums.size();
    if (ind == n)
    {
        return;
    }
    if (target == sum)
    {
        ans.push_back(v);
        return;
    }
    if (sum > target)
    {
        return;
    }
    sum += nums[ind];
    v.push_back(nums[ind]);
    combinationSum(nums, target, sum, v, ind, ans);
    sum -= nums[ind];
    v.pop_back();
    combinationSum(nums, target, sum, v, ind + 1, ans);
}

//subset sum 2 (unique subset)

void subsetSum2(vector<int>&nums,int ind,vector<vector<int>>&ans,vector<int>&v)
{
    ans.push_back(v);
    for(int i=ind;i<nums.size();i++)
    {
        //to avoid duplicates
        if(i!=ind && nums[i]==nums[i-1])
        {
            continue;
        }
        v.push_back(nums[ind]);
        subsetSum2(nums,ind+1,ans,v);
        v.pop_back();
    }
}


// strings

void solve(string ip, string op)
{
    if (ip.length() == 0)
    {
        cout << op << " ";
        return;
    }
    string op1 = op;
    string op2 = op;
    op1.push_back(ip[0]);
    ip.erase(ip.begin() + 0);
    solve(ip, op1);
    solve(ip, op2);
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
    // vector<int>v;
    // fn(nums,0,v);

    // string;
    //  string ip;
    //  cin>>ip;
    //  string op="";
    //  solve(ip,op);

    // subset sum
    //  vector<int>ans;
    //  vector<int>v;
    //  sumOfSubset(nums,v,ans,0);
    //  for(auto it:ans)
    //  {
    //      cout<<it<<" ";
    //  }
    //  cout<<endl;

    // combination sum
    // int target;
    // cin >> target;
    vector<int> v;
    vector<vector<int>> ans;
    subsetSum2(nums,0,ans,v);
    for (auto it : ans)
    {
        for (auto i : it)
        {
            cout << i << " ";
        }
        cout << endl;
    }
}