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
'n' cows given hai, and an array of the stall location, we need to place
'n' cows on the location such that the min distance between the cows is max

arr[]={0,3,4,7,10,9} cows=4

Intuition:

inn n cows ko place krni hai inn locations mein taaki unke beech jo min distance niklegi
woh max ho
low kya hogi? 1 hogi kyunki ek-ek distance mein rkh skte hai cows ko
high (max-min) hogi kyunki wahi sabse largest distance hogi na cows ke beech
since humein bss min distance between cows se mtlb hai, hum array ko sort krdenge
*/
bool isPossible(vector<int> nums, int n, int mid)
{
    int cnt = 1;
    int last = nums[0];
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] - last >= mid) //jo 2 cows ke beech mein distance hai and woh jo hum ek distance leke check kr 
        //rhe usse greater hona chahiye, nhi hua toh that two distances ke beech hum cow place nhi kr skte
        {
            cnt++;
            last = nums[i];
        }
    }
    return cnt >= n;
}
int solve(vector<int> &nums, int n)
{
    sort(nums.begin(), nums.end());
    int lo = 1;
    int hi = nums[nums.size() - 1] - nums[0];
    int ans = 0;
    while (lo <= hi)
    {
        int mid = lo + (hi - lo) / 2;
        if (isPossible(nums, n, mid))
        {
            ans = mid;
            lo = mid + 1; // kyunki max distance dhundh rahe
        }
        else
        {
            hi = mid - 1;
        }
    }
    return ans;
}
int main()
{
    vector<int> nums = {0, 3, 4, 7, 10, 9};
    cout << solve(nums, 4) << endl;
}