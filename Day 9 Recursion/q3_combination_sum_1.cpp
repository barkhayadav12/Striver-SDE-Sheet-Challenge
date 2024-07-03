class Solution
{
public:
    void printCombination(vector<int> &candidates, int i, int target, int sum, vector<vector<int>> &res, vector<int> &v)
    {
        if (i >= candidates.size())
        {
            return;
        }
        if (sum == target)
        {
            res.push_back(v);
            return;
        }
        if (sum > target)
        {
            return;
        }
        v.push_back(candidates[i]);
        sum += candidates[i];
        printCombination(candidates, i, target, sum, res, v);
        v.pop_back();
        sum -= candidates[i];
        printCombination(candidates, i + 1, target, sum, res, v);
    }
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<int> v;
        vector<vector<int>> res;
        printCombination(candidates, 0, target, 0, res, v);
        return res;
    }
};