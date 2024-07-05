class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int n1 = nums1.size();
        int n2 = nums2.size();
        // since we want to perform the operation on the smaller array, if n1>n2, we swap it
        if (n1 > n2)
        {
            swap(nums1, nums2);
            swap(n1, n2);
        }
        // When length is even, let's say 10 then left half length should be: (10+1)/2 =>5
        // When length is odd, let's say 11 then left half length should be: (11+1)/2 =>6
        // This mean that this formula gonna work in both condition
        int partition = (n1 + n2 + 1) / 2;
        int lo = 0;
        int hi = n1;
        while (lo <= hi)
        {
            int mid1 = (lo + hi) / 2;
            int mid2 = partition - mid1;
            int l1 = (mid1 == 0) ? INT_MIN : nums1[mid1 - 1];
            int l2 = (mid2 == 0) ? INT_MIN : nums2[mid2 - 1];
            int r1 = (mid1 == n1) ? INT_MAX : nums1[mid1];
            int r2 = (mid2 == n2) ? INT_MAX : nums2[mid2];
            if (l1 <= r2 && l2 <= r1)
            {
                // found the answer
                // if total length is odd
                if ((n1 + n2) % 2 == 1)
                {
                    return max(l1, l2);
                }
                else
                {
                    return ((double)(max(l1, l2) + min(r1, r2))) / 2.0;
                }
            }
            else if (l1 > r2)
            {
                hi = mid1 - 1;
            }
            else
            {
                lo = mid1 + 1;
            }
        }
        return 0.0;
    }
};