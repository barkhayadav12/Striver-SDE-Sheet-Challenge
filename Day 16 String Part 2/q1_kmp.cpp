class Solution
{
public:
    void computelps(vector<int> &lps, int m, string &needle)
    {
        int length = 0;
        lps[0] = 0;
        int i = 1;
        while (i < m)
        {
            if (needle[i] == needle[length])
            {
                length++;
                lps[i] = length;
                i++;
            }
            else
            {
                if (length != 0)
                {
                    length = lps[length - 1];
                }
                else
                {
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }
    int strStr(string haystack, string needle)
    {
        int n = haystack.length();
        int m = needle.length();
        int i = 0, j = 0;
        vector<int> lps(m, 0);
        computelps(lps, m, needle);
        int ans = -1;
        while (i < n)
        {
            if (haystack[i] == needle[j])
            {
                i++;
                j++;
            }
            if (j == m)
            {
                ans = (i - j);
                j = lps[j - 1];
                break;
            }
            else if (haystack[i] != needle[j])
            {
                if (j != 0)
                {
                    j = lps[j - 1];
                }
                else
                {
                    i++;
                }
            }
        }
        return ans;
    }
};