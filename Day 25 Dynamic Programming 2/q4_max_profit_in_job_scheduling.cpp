class Solution
{
public:
    // find index whose start time is greater than or equal to end time
    // start -- current index
    // end -- end time
    // have to start searching from curr index till the last index(n-1)
    int getNextIndex(vector<vector<int>> &jobs, int start, int end)
    {
        int lo = start;
        int hi = jobs.size() - 1;
        int res = hi + 1;
        while (lo <= hi)
        {
            int mid = lo + (hi - lo) / 2;
            // jobs[mid][0] -- start time
            if (jobs[mid][0] >= end) // if start time is greater than or equal to the given end time
            {
                res = mid;
                hi = mid - 1;
            }
            else
            {
                lo = mid + 1;
            }
        }
        return res;
    }
    int solve(vector<vector<int>> &jobs, int ind, int n, vector<int> &dp)
    {
        if (ind >= n)
        {
            return 0;
        }
        if (dp[ind] != -1)
        {
            return dp[ind];
        }
        // find next job
        int nextJob = getNextIndex(jobs, ind + 1, jobs[ind][1]);
        // take
        int take = jobs[ind][2] + solve(jobs, nextJob, n, dp);
        // not take
        int not_take = solve(jobs, ind + 1, n, dp);
        return dp[ind] = max(take, not_take);
    }
    int jobScheduling(vector<int> &startTime, vector<int> &endTime, vector<int> &profit)
    {
        int n = startTime.size();
        vector<vector<int>> jobs(n, vector<int>(3, 0));
        for (int i = 0; i < n; i++)
        {
            jobs[i][0] = startTime[i];
            jobs[i][1] = endTime[i];
            jobs[i][2] = profit[i];
        }
        // sort acc to start time
        sort(jobs.begin(), jobs.end());
        vector<int> dp(n + 1, -1);
        return solve(jobs, 0, n, dp);
    }
};