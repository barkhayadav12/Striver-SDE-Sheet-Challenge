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

/*
Find the smallest divisor such that the result mentioned above is less than or equal to threshold.
*/

bool isPossible(vector<int>&nums,int mid,int threshold)
{
    int sum=0;
    for(int i=0;i<nums.size();i++)
    {
        sum+=ceil((double)nums[i]/(double)mid);
    }
    return sum<=threshold;
}

int solve(vector<int>&nums,int threshold)
{
    int lo=1;
    int hi=(int)1e6;
    int ans=0;
    while(lo<=hi)
    {
        int mid=lo+(hi-lo)/2;
        if(isPossible(nums,mid,threshold))
        {
            ans=mid;
            hi=mid-1;  //smallest dhundhna hai
        }
        else{
            lo=mid+1;
        }
    }
    return ans;
}

int main()
{
    vector<int>nums={1,2,5,9};
    int threshold=6;
    cout<<solve(nums,threshold);
}