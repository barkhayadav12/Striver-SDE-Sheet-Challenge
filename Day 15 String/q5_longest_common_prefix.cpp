class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        sort(strs.begin(), strs.end());
        string first = strs[0];
        string last = strs[strs.size() - 1];
        string op = "";
        for (int i = 0; i < first.length(); i++)
        {
            if (first[i] == last[i])
            {
                op += first[i];
            }
            else
            {
                break;
            }
        }
        return op;
    }
};