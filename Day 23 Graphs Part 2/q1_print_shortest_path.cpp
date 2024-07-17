class Solution
{
public:
    vector<int> shortestPath(int n, int m, vector<vector<int>> &edges)
    {
        // create adjacency list
        // abhi input is in the form {1,2,2}, we need to change it
        // to 1 ->{2,2} form (1 ka adjacent node 2 hai and unke beech ka
        // distance is 2)
        vector<pair<int, int>> adj[n + 1];
        for (auto it : edges)
        {
            int node = it[0];
            int adjNode = it[1];
            int wt = it[2];
            adj[node].push_back({adjNode, wt});
            adj[adjNode].push_back({node, wt});
        }
        // create a distance array
        vector<int> dist(n + 1, 1e9);
        dist[1] = 0;
        // create min heap -- pair of distance and adjacent node
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 1});
        // create a parent array to keep track of ki hum kaha se aa rhe hai
        vector<int> parent(n + 1);
        for (int i = 1; i <= n; i++)
        {
            parent[i] = i;
        }
        while (!pq.empty())
        {
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for (auto it : adj[node])
            {
                int adjNode = it.first;
                int adjWt = it.second;
                if (dis + adjWt < dist[adjNode])
                {
                    dist[adjNode] = dis + adjWt;
                    pq.push({dis + adjWt, adjNode});
                    parent[adjNode] = node;
                }
            }
        }
        // if source node, destination node tak nhi pahunch paayi toh return -1
        if (dist[n] == 1e9)
        {
            return {-1};
        }
        // else path print krdo...pehle destination node se start karenge phir dekhenge uska parent node kaunsa hai
        // and so on
        vector<int> path;
        int node = n;
        while (parent[node] != node)
        {
            path.push_back(node);
            node = parent[node];
        }
        path.push_back(1);
        path.push_back(dist[n]);
        reverse(path.begin(), path.end());
        return path;
    }
};