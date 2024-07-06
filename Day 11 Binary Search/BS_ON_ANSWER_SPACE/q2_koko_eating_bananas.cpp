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
need to return the minimum integer k such that koko can eat all the bananas within h hours.
k - no. of bananas per hour

Question: How many bananas should koko eat per hour (which is k) so that she can eat all the bananas 
from the pile.

Identification:
There is monotonicity i.e k can be from 1 to the max of the given piles. 

Given: nums[]={3,6,7,11}  h=8

Koko 1hr mein 1 banana kha skta hai, tab k would be = 27 , which is greater than h
Suppose karo koko eats 4bananas per hr, then k would be = 8, which is fine

For this case, if koko eats 11bananas per hr, then k would be = 4, which is fine.
Koko can eat per hr 12,13,etc also but that wouldn't make a difference because k will still
be k, so we are taking the high value as 11(i.e max among the given piles). We need to find the
min k?
*/

bool isPossible(vector<int>&nums,int mid,int time)
{
    int cnt=0;
    for(int i=0;i<nums.size();i++)
    {
        cnt+=ceil((double)nums[i]/(double)mid);
    }
    return cnt<=time;
}

int solve(vector<int>&nums, int time)
{
    int lo=1;
    int hi=*max_element(nums.begin(),nums.end());
    int ans=0;
    while(lo<=hi)
    {
        int mid=lo+(hi-lo)/2;
        if(isPossible(nums,mid,time))
        {
            ans=mid;
            hi=mid-1; //because min find krni hai
        }
        else{
            lo=mid+1;
        }
    }
    return ans;
}

int main()
{
    vector<int>nums={3,6,7,11};
    cout<<solve(nums,8)<<endl;
}