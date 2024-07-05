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
#include <climits>
using namespace std;

// binary search (eliminate one half either left or right)

bool isPresent(vector<int> &nums, int target)
{
    int n = nums.size();
    int lo = 0;
    int hi = n - 1;
    while (lo <= hi)
    {
        int mid = lo + (hi - lo) / 2;
        if (nums[mid] == target)
        {
            return true;
        }
        if (nums[mid] > target)
        {
            hi = mid - 1;
        }
        else
        {
            lo = mid + 1;
        }
    }
    return false;
}

// lower bound : returns the smallest number that is just greater than or equal to that number

int lowerBound(vector<int> &nums, int target)
{
    int n = nums.size();
    int lo = 0;
    int hi = n - 1;
    int ans = 0;
    while (lo <= hi)
    {
        int mid = lo + (hi - lo) / 2;
        if (nums[mid] >= target)
        {
            ans = nums[mid];
            hi = mid - 1;
        }
        else
        {
            lo = mid + 1;
        }
    }
    return ans;
}

// upper bound : returns the smallest index that is greater than value, or last if not found

int upperBound(vector<int> &nums, int target)
{
    int n = nums.size();
    int lo = 0;
    int hi = n - 1;
    int ans = nums[n - 1];
    while (lo <= hi)
    {
        int mid = lo + (hi - lo) / 2;
        if (nums[mid] > target)
        {
            ans = nums[mid];
            hi = mid - 1;
        }
        else
        {
            lo = mid + 1;
        }
    }
    return ans;
}

// search element in rotated sorted array

// nums[]={7,8,9,1,2,3,4,5,6}

int isPresentInRotated(vector<int> &nums, int target)
{
    int n = nums.size();
    int lo = 0;
    int hi = n - 1;
    while (lo <= hi)
    {
        int mid = lo + (hi - lo) / 2;
        if (nums[mid] == target)
        {
            return mid;
        }
        // eleminate one half, either left or right

        /*agar koi ek half sorted hai toh, hum jo target value hai woh nums[mid] && nums[lo](/nums[hi]) inn dono range ke beech
        lie krti hai kya check kr rhe, agar woh value uss range mein hai, toh we know ki humein woh dusre half ki jarurat nhi
        hai, yeh present half mein hi answer milegi, logic yeh hai*/

        if (nums[mid] < nums[lo]) // left half unsorted hai kyunki nums[lo]>nums[mid] se
        {
            if (nums[mid] <= target && target <= nums[hi])
            {
                lo = mid + 1;
            }
            else
            {
                hi = mid - 1;
            }
        }
        else
        { // left sorted hai
            if (nums[lo] <= target && nums[mid] >= target)
            {
                hi = mid - 1;
            }
            else
            {
                lo = mid + 1;
            }
        }
    }
}

// minimum in sorted rotated array

// nums[]={4,5,6,7,0,1,2}

int minInRotated(vector<int> &nums)
{
    int n = nums.size();
    int lo = 0;
    int hi = n - 1;
    int ans = INT_MAX;
    while (lo <= hi)
    {
        int mid = lo + (hi - lo) / 2;
        // if left half is sorted
        if (nums[mid] >= nums[lo])
        {
            // keep the min
            ans = min(ans, nums[lo]);
            // eliminate the left half
            lo = mid + 1;
        }
        else // if right half is sorted
        {
            ans = min(ans, nums[mid]);
            hi = mid - 1;
        }
    }
    return ans;
}

int main()
{
    // vector<int>nums={1,2,3,5};
    // isPresent(nums,10)?cout<<"YES\n":cout<<"NO\n";
    // cout<<lowerBound(nums,2)<<endl;
    // cout<<upperBound(nums,2)<<endl;
    vector<int> nums = {7, 8, 9, 1, 2, 3, 4, 5, 6};
    cout << isPresentInRotated(nums, 8) << endl;
    cout << minInRotated(nums) << endl;
}