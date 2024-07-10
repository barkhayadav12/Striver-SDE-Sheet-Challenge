int computelps(string &op)
{
    int m = op.size();
    vector<int> lps(m, 0);
    int length = 0;
    lps[0] = 0;
    int i = 1;
    while (i < m)
    {
        if (op[i] == op[length])
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
    return lps[m - 1];
}
int Solution::solve(string A)
{
    int n = A.size();
    string rev = A;
    reverse(rev.begin(), rev.end());
    string op = A + "$" + rev;
    int matched = computelps(op);
    return n - matched;
}
