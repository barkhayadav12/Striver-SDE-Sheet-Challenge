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
Kuch books given hongi(books ke pages given hai) and number of students given hongi,
humein unn books(pages) ko distribute krni hai students ko such that maximum number of papers
assigned to a student is minimum

arr[]=[25,46,28,49,24] n=4

Condition hai: Every student should get 1 book alteast

Suppose karo ki arr.size() == n hai toh har student ko ek hi book milegi
tab jo max number of pages jin bache ko mila hoga woh, jo book array mein max hai
wahi hoga

But yaha aisa nhi hai, ek extra hai(according to the example), toh woh extra humein kisi
ek bache ko deni hogi, mtlb ek student 2 books receive karega,
Suppose student 1 ko first ka 2 mila: 1st student=25+46=71, 2nd student=28, 49, 24
Suppose student 2 ko first ka 2 mila: 1st student=25, 2nd student=46+28=74, 49, 24
Suppose student 3 ko first ka 2 mila: 1st student=25, 2nd student=46, 28+49=77, 24
Suppose student 4 ko first ka 2 mila: 1st student=25, 2nd student=46, 28, 49+24=73

Yaha par min kaunsa hai, that is when 1st student got 2 books, toh wahi answer hai

Why binary Search?
Monotonicity hai, humara low arr mein jo max hai wahi hoga, kyunki agar usse kam liya
toh kuch students ko book nhi milega. har book kisi na kisi student ko dena hai, ek book
ek hi student ko jayegi, high sum of arr hogi, kyunki worst case mein 1 student hui toh
saare books ussi ko milega
Range max(arr)-->sum(arr) hogi, iske beech mein humare answer hai
*/

bool isPossible(vector<int> &nums, int mid, int n)
{
    int cnt = 1;
    int sum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (sum + nums[i] > mid)
        {
            cnt++;
            sum = nums[i];
        }
        else
        {
            sum += nums[i];
        }
    }
    return cnt <= n;
}
int solve(vector<int> &nums, int n)
{
    if (nums.size() < n)
    {
        return -1;
    }
    int lo = *max_element(nums.begin(), nums.end());
    int hi = accumulate(nums.begin(), nums.end(), 0);
    int ans = -1;
    while (lo <= hi)
    {
        int mid = lo + (hi - lo) / 2;
        if (isPossible(nums, mid, n))
        {
            ans = mid;
            hi = mid - 1;
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
    vector<int> nums = {25, 46, 28, 49, 24};
    cout << solve(nums, 4) << endl;
}