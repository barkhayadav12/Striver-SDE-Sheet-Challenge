class Solution
{
public:
    bool isPalindrome(string s, int ind, int i)
    {
        while (ind <= i)
        {
            if (s[ind] != s[i])
            {
                return false;
            }
            ind++;
            i--;
        }
        return true;
    }
    void fn(string s, vector<string> &v, vector<vector<string>> &ans, int ind)
    {
        if (ind == s.length())
        {
            ans.push_back(v);
            return;
        }
        for (int i = ind; i < s.length(); i++)
        {
            if (isPalindrome(s, ind, i))
            {
                v.push_back(s.substr(ind, i - ind + 1));
                fn(s, v, ans, i + 1);
                v.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s)
    {
        vector<string> v;
        vector<vector<string>> ans;
        fn(s, v, ans, 0);
        return ans;
    }
};