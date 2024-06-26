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

int findRepeatingAndMissing(vector<int>&nums)
{
    int n=nums.size();
    unordered_map<int,int>mpp;
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=nums[i];
        mpp[nums[i]]++;
    }
    int duplicate=0;
    for(auto it:mpp)
    {
        if(it.second>1)
        {
            duplicate=it.first;
            break;
        }
    }
    int maxi=*max_element(nums.begin(),nums.end());
    int tot_sum=((maxi)*(maxi+1))/2;
    int missing=tot_sum-(sum-duplicate);
    return missing;
}

int main()
{
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++)
    {
        cin>>nums[i];
    }
    cout<<findRepeatingAndMissing(nums)<<endl;
}