class Solution
{
public:
    bool solve(vector<vector<int>> &graph, vector<int> &color, int col, int node)
    {
        color[node] = col;
        for (auto it : graph[node])
        {
            if (color[it] == -1)
            {
                if (solve(graph, color, !col, it) == false)
                {
                    return false;
                }
            }
            else if (color[it] == col)
            {
                return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>> &graph)
    {
        vector<int> color(graph.size(), -1);
        int col = 0;
        for (int i = 0; i < graph.size() - 1; i++)
        {
            if (color[i] == -1)
            {
                if (solve(graph, color, col, i) == false)
                {
                    return false;
                }
            }
        }
        return true;
    }
};