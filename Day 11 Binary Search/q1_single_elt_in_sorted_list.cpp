class Solution
{
public:
    int singleNonDuplicate(vector<int> &nums)
    {
        int n = nums.size();
        // edge case
        if (n == 1)
        {
            return nums[0];
        }
        if (nums[0] != nums[1])
        {
            return nums[0];
        }
        if (nums[n - 1] != nums[n - 2])
        {
            return nums[n - 1];
        }
        int lo = 1;
        int hi = n - 2;
        while (lo <= hi)
        {
            int mid = lo + (hi - lo) / 2;
            // if an elt is supposed to be the single elt,its left elt or its right elt will not be same as that elt
            if (nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1])
            {
                return nums[mid];
            }
            // the elts on the left of the single elt exists as (even,odd) index pairs whereas the elts on its right exists as (odd,even) index pairs
            /*how would we know if we need to eliminate the left part or the right part?
            for left part- elt pairs exist as even, odd index pairs, if we are currently on left part, to get the answer we need
            to move right, hence we need to eliminate left part
            for right part- elt pairs exist as odd, even index pairs, if we are currently on right part, to get the answer we need
            to move left, hence we need to eliminate right part
            */
            if ((mid % 2 == 1 && nums[mid] == nums[mid - 1]) || (mid % 2 == 0 && nums[mid] == nums[mid + 1]))
            {
                lo = mid + 1;
            }
            else
            {
                hi = mid - 1;
            }
        }
        return 1;
    }
};