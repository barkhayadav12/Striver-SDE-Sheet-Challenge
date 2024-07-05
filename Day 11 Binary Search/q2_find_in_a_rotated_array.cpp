class Solution
{
public:
    int search(vector<int> &nums, int target)
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
        return -1;
    }
};