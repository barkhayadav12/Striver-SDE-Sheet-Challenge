class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> stk;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
            {
                stk.push(s[i]);
            }
            else
            {
                if (stk.size() == 0)
                {
                    return false;
                }
                char temp = stk.top();
                stk.pop();
                if (s[i] == ')' && temp == '(' || s[i] == ']' && temp == '[' || s[i] == '}' && temp == '{')
                {
                    continue;
                }
                else
                {
                    return false;
                }
            }
        }
        if (!stk.empty())
        {
            return false;
        }
        else
        {
            return true;
        }
    }
};