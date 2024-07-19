class Solution
{
public:
    bool solve(int idx, int n, string &s, vector<int> &dp, unordered_set<string> &st)
    {
        // base case
        // if last tak pahunch gaye hai toh saare substring compare krne ke baad true aa rha isiliye last tak pahunche hai
        if (idx == n)
        {
            return true;
        }
        // one more base case, if jo string hai usko break krne hi na pade toh, agar woh dictionary mein already present hai toh return true
        if (st.find(s) != st.end())
        {
            return true;
        }
        if (dp[idx] != -1)
        {
            return dp[idx];
        }
        for (int l = 1; l <= n; l++)
        {
            string temp = s.substr(idx, l);
            // find in dictionary, if found, baaki ke remaining string bhi present hai kya check karo
            if ((st.find(temp) != st.end()) && solve(idx + l, n, s, dp, st))
            {
                return dp[idx] = true;
            }
        }
        return dp[idx] = false;
    }
    bool wordBreak(string s, vector<string> &wordDict)
    {
        int n = s.length();
        unordered_set<string> st(wordDict.begin(), wordDict.end());
        vector<int> dp(301, -1);
        return solve(0, n, s, dp, st);
    }
};