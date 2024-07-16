class Solution
{
public:
    // Function to return list containing vertices in Topological order.
    void topo(vector<int> adj[], stack<int> &stk, vector<int> &vis, int node)
    {
        vis[node] = 1;
        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                topo(adj, stk, vis, it);
            }
        }
        stk.push(node);
    }
    vector<int> topoSort(int V, vector<int> adj[])
    {
        stack<int> stk;
        vector<int> vis(V, 0);
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                topo(adj, stk, vis, i);
            }
        }
        vector<int> ans;
        while (!stk.empty())
        {
            ans.push_back(stk.top());
            stk.pop();
        }
        return ans;
    }
};