class Solution
{
public:
    void printCombination(vector<int> &candidates, int index, int target, vector<int> &v, vector<vector<int>> &ans)
    {
        if (target == 0)
        {
            ans.push_back(v);
            return;
        }
        for (int i = index; i < candidates.size(); i++)
        {
            if (i != index && candidates[i] == candidates[i - 1])
            {
                continue;
            }
            if (candidates[i] > target)
            {
                break;
            }
            v.push_back(candidates[i]);
            printCombination(candidates, i + 1, target - candidates[i], v, ans);
            v.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        vector<int> v;
        vector<vector<int>> ans;
        printCombination(candidates, 0, target, v, ans);
        return ans;
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
            if(i!=ind && candidates[i]==candidates[i-1])
            {
                continue;
            }
            v.push_back(candidates[i]);
            solve(candidates,target-candidates[i],v,ans,i+1,n);
            v.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>ans;
        vector<int>v;
        int n=candidates.size();
        solve(candidates,target,v,ans,0,n);
        return ans;
    }
};
