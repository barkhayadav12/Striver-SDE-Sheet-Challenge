// this gives tle
// no. of attempts dhundhna hai (min)
// Question? Worst case mein kitne floors check krne honge, unn worst cases mein se min nikalni hai
class Solution
{
public:
    int solve(int k, int n, vector<vector<int>> &dp)
    {
        // base case
        // agar no. of floors 0 hua toh 0 attempts krne honge and 1 hi floor hua toh no. of attempts 1 hai
        if (n == 0 || n == 1)
        {
            return n;
        }
        // egg 1 given hoga toh worst case mein humein saare floors dekhne honge
        if (k == 1)
        {
            return n;
        }
        if (dp[k][n] != -1)
        {
            return dp[k][n];
        }
        int ans = INT_MAX;
        for (int i = 1; i <= n; i++)
        {
            /*
            2 case arise:
            1. agar uss particular floor mein egg break kr rhi hai toh threshold dhundhne ke liye
            humein neeche wale floor check krne padenge

            **Threshold or critical floor** - jis floor ke upar egg break krna start hogi or neeche wale floors mein
            egg break nhi karenge

            2. agar egg break nhi kri uss particular floor mein toh humein upar wale floors mein check krna hoga

            Why taking max? Because humein check krni hai ki worst case mein humein kitne attempts krne honge

            And again min? Unn worst case wale attempts mein se jo min hai wahi answer hoga
            */
            int temp = 1 + max(solve(k - 1, i - 1, dp), solve(k, n - i, dp));
            ans = min(ans, temp);
        }
        return dp[k][n] = ans;
    }
    int superEggDrop(int k, int n)
    {
        vector<vector<int>> dp(k + 1, vector<int>(n + 1, -1));
        return solve(k, n, dp);
    }
};

// dp + binary search (works)

class Solution
{
public:
    int solve(int k, int n, vector<vector<int>> &dp)
    {
        // base case
        if (n == 0 || n == 1)
        {
            return n;
        }
        if (k == 1)
        {
            return n;
        }
        if (dp[k][n] != -1)
        {
            return dp[k][n];
        }
        int ans = INT_MAX;
        int lo = 1, hi = n, temp = 0;
        while (lo <= hi)
        {
            int mid = (lo + hi) / 2;              // k
            int left = solve(k - 1, mid - 1, dp); // if break kr gayi, toh neeche ke floors mein dekhenge
            int right = solve(k, n - mid, dp);    // if break nhi kri, toh upar dekhenge
            // taking jo max aayegi
            temp = 1 + max(left, right);
            // humein worst case wale attempts mein se min dhundhna hai so right se max mil rhi toh right se taraf jaa rhe
            if (left < right)
            {
                lo = mid + 1;
            } // else left mein max aa rhi toh left mein jaa rhi
            else
            {
                hi = mid - 1;
            }
            // max attempts wale mein se min wala kaunsa hai
            ans = min(ans, temp);
        }
        return dp[k][n] = ans;
    }
    int superEggDrop(int k, int n)
    {
        vector<vector<int>> dp(k + 1, vector<int>(n + 1, -1));
        return solve(k, n, dp);
    }
};

// define attempts? agar 1 se start kiya toh kya answer hoga, 2 se start kiya toh kya answer hoga and so on