class Solution
{
public:
    // Function to find the shortest distance of all the vertices
    // from the source vertex S.
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // create a distance array and initially assign it to infinity
        // why? because abhi we don't know ki woh node source se reachable bhi
        // hai ya nhi, agar reachable hai toh kitni doori par hai
        vector<int> dist(V);
        for (int i = 0; i < V; i++)
        {
            dist[i] = 1e9;
        }
        dist[S] = 0;
        // create a min heap - pair of distance and adjacent node
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, S});
        while (!pq.empty())
        {
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            // adjacent nodes par traverse karo
            for (auto it : adj[node])
            {
                int adjNode = it[0];
                int adjWt = it[1];
                if (adjWt + dis < dist[adjNode])
                {
                    dist[adjNode] = dis + adjWt;
                    pq.push({dis + adjWt, adjNode});
                }
            }
        }
        return dist;
    }
};
