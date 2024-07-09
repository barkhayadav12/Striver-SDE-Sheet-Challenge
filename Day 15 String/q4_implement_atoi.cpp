class Solution
{
public:
    int myAtoi(string s)
    {
        int temp = 0;
        int ans = 0;
        // skipping whitespaces
        while (temp < s.length())
        {
            if (s[temp] == ' ')
            {
                temp++;
            }
            else
            {
                break;
            }
        }
        // checking for sign
        bool isNeg = false;
        if (s[temp] == '-')
        {
            isNeg = true;
            temp++;
        }
        else if (s[temp] == '+')
        {
            temp++;
        }
        // skipping leading zeroes
        while (temp < s.length())
        {
            if (s[temp] == '0')
            {
                temp++;
            }
            else
            {
                break;
            }
        }
        for (int i = temp; i < s.length(); i++)
        {
            if (isalpha(s[i]) || s[i] == '+' || s[i] == '-' || s[i] == '.' || s[i] == ' ')
            {
                break;
            }
            int x = s[i] - '0';
            // checking overflow
            if (ans > (INT_MAX / 10) || (ans == (INT_MAX / 10) && x > 7))
            {
                return isNeg ? INT_MIN : INT_MAX;
            }
            if (isdigit(s[i]))
            {
                ans = ans * 10 + x;
            }
        }
        if (isNeg)
        {
            ans = -ans;
            return ans;
        }
        return ans;
    }
};