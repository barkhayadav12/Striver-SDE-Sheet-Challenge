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
#include <numeric>
using namespace std;

//next greater element to left

int main()
{
    vector<int>nums={1,3,2,4};
    stack<int>stk;
    vector<int>ans;
    for(int i=0;i<nums.size();i++)
    {
        if(stk.size()==0)
        {
            ans.push_back(-1);
        }
        else if(stk.size()>0 && stk.top()>nums[i])
        {
            ans.push_back(stk.top());
        }
        else if(stk.size()>0 && stk.top()<=nums[i])
        {
            while(!stk.empty() && stk.top()<=nums[i])
            {
                stk.pop();
            }
            if(stk.size()==0)
            {
                ans.push_back(-1);
            }
            else{
                ans.push_back(stk.top());
            }
        }
        stk.push(nums[i]);
    }
    for(auto it:ans)
    {
        cout<<it<<" ";
    }
}