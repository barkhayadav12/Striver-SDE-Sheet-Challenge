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

/*
Question padhte time thodi confusing lagti hai, question mein ek weight array given hai and "d"
days given hai. Ships 'd' days chlne wali hai, unn 'd' days (ya usse kam days mein) mein humein jo
given packages woh deliver krne ki. So pucha hai ki ship least capacity kitna le jaaye per day ki yeh saare
packages deliver ho jaaye

weights[]=[1,2,3,4,5,6,7,8,9,10] days=5

Intuition:
low humari 1 hogi kyunki woh din ka 1wt le jaa skta hai(in case number of days permit kare toh)
and high humari sum of all weights hogi kyunki ek din mein saare wts bhi toh le jaa skta hai, par twist
yeh hai humein least capacity find krni hai and 'd' days mein sab deliver bhi ho jaaye
*/

bool isPossible(vector<int> &nums, int mid, int days)
{
    int cnt = 1;
    int sum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (sum + nums[i] > mid)
        {
            cnt+=1;
            sum = nums[i];
        }else{
            sum += nums[i];
        }
    }
    return cnt <= days;
}

int solve(vector<int> &nums, int days)
{
    int lo = 1;
    int hi = accumulate(nums.begin(), nums.end(), 0);
    int ans = 0;
    while (lo <= hi)
    {
        int mid = lo + (hi - lo) / 2;
        if (isPossible(nums, mid, days))
        {
            ans = mid;
            hi = mid - 1; // kyunki least pucha hai
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
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << solve(nums, 5) << endl;
}