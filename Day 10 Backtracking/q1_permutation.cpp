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

void printPermutation(vector<int>&nums,vector<vector<int>>&ans,int ind)
{
    if(ind==nums.size())
    {
        ans.push_back(nums);
        return;
    }
    for(int i=ind;i<nums.size();i++)
    {
        swap(nums[i],nums[ind]);
        printPermutation(nums,ans,ind+1);
        swap(nums[i],nums[ind]);
    }
}
int main()
{
    vector<int>nums={1,2,3};
    vector<vector<int>>ans;
    printPermutation(nums,ans,0);
    for(auto it:ans)
    {
        for(auto i:it)
        {
            cout<<i<<" ";
        }
        cout<<endl;
    }
}