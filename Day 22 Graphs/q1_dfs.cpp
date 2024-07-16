class Solution
{
public:
    // Function to return a list containing the DFS traversal of the graph.
    void dfs(vector<int> adj[], vector<int> &vis, vector<int> &ans, int node)
    {
        vis[node] = 1;
        ans.push_back(node);
        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                dfs(adj, vis, ans, it);
            }
        }
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[])
    {
        // Code here
        vector<int> vis(V, 0);
        vector<int> ans;
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                dfs(adj, vis, ans, i);
            }
        }
        return ans;
    }
};