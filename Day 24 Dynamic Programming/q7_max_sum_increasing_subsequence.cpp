class Solution
{
public:
    int maxSumIS(int arr[], int n)
    {
        // Your code goes here
        int msis[n];
        for (int i = 0; i < n; i++)
        {
            msis[i] = arr[i];
        }
        int maxi = arr[0];
        for (int i = 1; i < n; i++)
        {
            for (int prev = 0; prev < i; prev++)
            {
                if (arr[i] > arr[prev] && msis[i] < arr[i] + msis[prev])
                {
                    msis[i] = arr[i] + msis[prev];
                }
            }
            maxi = max(maxi, msis[i]);
        }
        return maxi;
    }
};