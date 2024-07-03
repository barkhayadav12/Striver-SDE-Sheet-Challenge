//return sum of all subsets
class Solution {
  public:
    void fn(vector<int>&arr,int n,int ind,vector<int>&v,vector<int>&ans)
    {
        //base case
        if(ind==n)
        {
            int sum=0;
            for(auto it:v)
            {
                sum+=it;
            }
            ans.push_back(sum);
            return;
        }
        //pick
        v.push_back(arr[ind]);
        fn(arr,n,ind+1,v,ans);
        //don't pick
        v.pop_back();
        fn(arr,n,ind+1,v,ans);
    }
    vector<int> subsetSums(vector<int> arr, int n) {
        // Write Your Code here
        vector<int>ans;
        vector<int>v;
        fn(arr,n,0,v,ans);
        return ans;
    }
};
