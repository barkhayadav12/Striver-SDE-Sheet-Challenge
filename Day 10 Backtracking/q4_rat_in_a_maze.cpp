class Solution
{
public:
    void solve(vector<vector<int>> &m, int i, int j, int n, string op, vector<string> &ans, vector<vector<int>> &vis)
    {
        if (i == n - 1 && j == n - 1)
        {
            ans.push_back(op);
            return;
        }
        // since we have to print in lexographical order, we go in this order- first down,left,right,up
        // down
        if (i + 1 < n && !vis[i + 1][j] && m[i + 1][j] == 1)
        {
            vis[i][j] = 1;
            solve(m, i + 1, j, n, op + 'D', ans, vis);
            // backtrack
            vis[i][j] = 0;
        }
        // left
        if (j - 1 >= 0 && !vis[i][j - 1] && m[i][j - 1] == 1)
        {
            vis[i][j] = 1;
            solve(m, i, j - 1, n, op + 'L', ans, vis);
            // backtrack
            vis[i][j] = 0;
        }
        // right
        if (j + 1 < n && !vis[i][j + 1] && m[i][j + 1] == 1)
        {
            vis[i][j] = 1;
            solve(m, i, j + 1, n, op + 'R', ans, vis);
            // backtrack
            vis[i][j] = 0;
        }
        // up
        if (i - 1 >= 0 && !vis[i - 1][j] && m[i - 1][j] == 1)
        {
            vis[i][j] = 1;
            solve(m, i - 1, j, n, op + 'U', ans, vis);
            // backtrack
            vis[i][j] = 0;
        }
    }
    vector<string> findPath(vector<vector<int>> &m, int n)
    {
        // Your code goes here
        vector<string> ans;
        string op = "";
        vector<vector<int>> vis(n, vector<int>(n, 0));
        if (m[0][0] == 1)
        {
            solve(m, 0, 0, n, op, ans, vis);
        }
        return ans;
    }
};
