class Solution
{
public:
    // Function to detect cycle in an undirected graph.
    bool cycle(vector<int> adj[], int node, vector<int> &vis, int parent)
    {
        vis[node] = 1;
        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                if (cycle(adj, it, vis, node) == true)
                {
                    return true;
                }
            }
            else if (it != parent)
            {
                return true;
            }
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[])
    {
        // Code here
        vector<int> vis(V, 0);
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                if (cycle(adj, i, vis, -1) == true)
                {
                    return true;
                }
            }
        }
        return false;
    }
};