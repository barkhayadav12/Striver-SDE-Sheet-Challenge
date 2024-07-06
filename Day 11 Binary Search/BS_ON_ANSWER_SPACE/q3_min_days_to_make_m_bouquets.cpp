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
need to make 'm' bouquets with 'k' adjacent flowers

bloomday of the flowers is given, we need to return the min number
of days to wait to be able to make m bouquets.

bloomDay = [1,10,3,10,2], m = 3, k = 1

Identification:
There is monotonicity because days can be from min bloomday to
the max bloomday. Min bloomday humari low hogi kyunki uss din ke pehle
koi bhi flower bloom nhi kr rhi and max bloomday ke baad ke baad saare flowers
bloom ho gayi hogi, tab hum agar using 'k' adjacent flowers 'm'
bouquets bna skte hai toh woh return krni hai (remember we need to find min), nhi
bna skte toh -1 return krdenge

*/

bool isPossible(vector<int> &nums, int mid, int k, int m)
{
    int cnt = 0;
    int ans = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (mid >= nums[i])
        {
            cnt++;
        }
        else
        {
            ans += (cnt / k);
            cnt = 0;
        }
    }
    ans += (cnt / k);
    return ans >= m;
}

int solve(vector<int> &nums, int m, int k)
{
    int lo = *min_element(nums.begin(), nums.end());
    int hi = *max_element(nums.begin(), nums.end());
    int ans = -1;
    while (lo <= hi)
    {
        int mid = lo + (hi - lo) / 2;
        if (isPossible(nums, mid, k, m))
        {
            ans = mid;
            hi = mid - 1; // kyunki min find kr rhe hum
        }
        else
        {
            lo = mid + 1;
        }
    }
    return ans;
}
int main()
{
    vector<int> nums = {1, 10, 3, 10, 2};
    cout << solve(nums, 3, 1) << endl;
}