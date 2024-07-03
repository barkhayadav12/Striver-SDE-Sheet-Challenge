class Solution {
public:
    void printSubset(vector<int>&nums,int index,vector<int>&v,vector<vector<int>>&ans)
    {
        ans.push_back(v);
        for(int i=index;i<nums.size();i++)
        {
            //to avoid taking duplicate values
            if(i!=index && nums[i]==nums[i-1])
            {
                continue;
            }
            v.push_back(nums[i]);
            printSubset(nums,i+1,v,ans);
            v.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>v;
        vector<vector<int>>ans;
        printSubset(nums,0,v,ans);
        return ans;
    }
};