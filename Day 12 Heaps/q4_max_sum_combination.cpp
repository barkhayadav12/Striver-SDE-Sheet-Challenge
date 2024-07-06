//normal wali gives tle, so time complexity reduce krne ke liye itne checks laga rhe
vector<int> Solution::solve(vector<int> &A, vector<int> &B, int C)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    sort(A.rbegin(), A.rend());
    sort(B.rbegin(), B.rend());
    int n = A.size();
    int m = B.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (pq.size() < C)
            {
                pq.push(A[i] + B[j]);
            }
            else
            {
                if (A[i] + B[j] > pq.top())
                {
                    pq.pop();
                    pq.push(A[i] + B[j]);
                }
                else
                {
                    break;
                }
            }
        }
    }
    vector<int> ans;
    while (!pq.empty())
    {
        ans.push_back(pq.top());
        pq.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
