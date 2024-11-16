class Solution
{
public:
    void printCombination(vector<int> &candidates, int i, int target, int sum, vector<vector<int>> &res, vector<int> &v)
    {
        if (i >= candidates.size())
        {
            return;
        }
        if (sum == target)
        {
            res.push_back(v);
            return;
        }
        if (sum > target)
        {
            return;
        }
        v.push_back(candidates[i]);
        sum += candidates[i];
        printCombination(candidates, i, target, sum, res, v);
        v.pop_back();
        sum -= candidates[i];
        printCombination(candidates, i + 1, target, sum, res, v);
    }
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<int> v;
        vector<vector<int>> res;
        printCombination(candidates, 0, target, 0, res, v);
        return res;
    }
};


//another way
class Solution {
public:
    void solve(vector<int>&candidates,int target,vector<int>&v,vector<vector<int>>&ans,int ind,int n)
    {
        if(target<0)
        {
            return;
        }
        if(target==0)
        {
            ans.push_back(v);
        }
        for(int i=ind;i<n;i++)
        {
            v.push_back(candidates[i]);
            solve(candidates,target-candidates[i],v,ans,i,n);
            v.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>v;
        int n=candidates.size();
        solve(candidates,target,v,ans,0,n);
        return ans;
    }
};
