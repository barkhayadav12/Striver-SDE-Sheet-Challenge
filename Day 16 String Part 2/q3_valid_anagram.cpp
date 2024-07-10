class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        int x = s.length();
        int y = t.length();
        map<char, int> mpp;
        int flag = 0;
        if (x != y)
        {
            return false;
        }
        else
        {
            for (int i = 0; i < x; i++)
            {
                mpp[s[i]]++;
            }
            for (int i = 0; i < x; i++)
            {
                mpp[t[i]]--;
            }
            for (auto it : mpp)
            {
                int c = it.second;
                if (c < 0 || c > 0)
                {
                    flag = 1;
                }
            }
            if (flag == 1)
            {
                return false;
            }
            else
            {
                return true;
            }
        }
    }
};