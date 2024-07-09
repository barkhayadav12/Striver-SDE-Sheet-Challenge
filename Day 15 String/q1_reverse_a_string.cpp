class Solution
{
public:
    string reverseWords(string s)
    {
        stack<string> stk;
        string op = "";
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] != ' ')
            {
                op += s[i];
            }
            else if (s[i] == ' ' && op.length() != 0)
            {
                stk.push(op);
                op = "";
            }
        }
        if (op.length() > 0)
        {
            stk.push(op);
        }
        string ans = "";
        while (stk.size() > 1)
        {
            ans += stk.top();
            ans += ' ';
            stk.pop();
        }
        ans += stk.top();
        stk.pop();
        return ans;
    }
};