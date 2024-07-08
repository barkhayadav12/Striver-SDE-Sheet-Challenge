vector<int> Solution::prevSmaller(vector<int> &A)
{
    vector<int> ans;
    stack<int> stk;
    for (int i = 0; i < A.size(); i++)
    {
        if (stk.size() == 0)
        {
            ans.push_back(-1);
        }
        else if (stk.size() > 0 && stk.top() < A[i])
        {
            ans.push_back(stk.top());
        }
        else if (stk.size() > 0 && stk.top() >= A[i])
        {
            while (!stk.empty() && stk.top() >= A[i])
            {
                stk.pop();
            }
            if (stk.size() == 0)
            {
                ans.push_back(-1);
            }
            else
            {
                ans.push_back(stk.top());
            }
        }
        stk.push(A[i]);
    }
    return ans;
}
