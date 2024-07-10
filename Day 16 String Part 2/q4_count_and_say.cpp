class Solution
{
public:
    string countAndSay(int n)
    {
        string op = "";
        op += "1";
        n--;
        while (n > 0)
        {
            string temp = "";
            for (int i = 0; i < op.length(); i++)
            {
                int cnt = 1;
                while ((i + 1) < op.length() && op[i] == op[i + 1])
                {
                    cnt++;
                    i++;
                }
                temp += to_string(cnt) + op[i];
            }
            op = temp;
            n--;
        }
        return op;
    }
};