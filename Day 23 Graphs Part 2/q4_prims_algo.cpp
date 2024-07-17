/*
Minimum spanning tree : A tree in which we have 'N' nodes and 'N-1' edges and all the nodes are reachable
from each other

Prim's algorithm : 

Kaise work krti hai ?
Pehle toh hum source node or starting node visit kr rhe hai and priority queue mein push krdi,
and hum greedy approach use kr rhe hai, greedy kaise?

Humne ek node visit krli, uske baad agar uski adjacent node unvisited hai toh humne priority queue mein daal diya
hai, isse kya ho rha hai ki, jo current node hai uski bahut saari adjacent node ho skti hai aur according to
the concept of MST humein jo min edge weight hai usse leni hai, toh jab humne priority queue mein add kri, tab jo
min edge weight hai woh top pe aa rha, toh in this way hum saare min wale edge weight wale pehle visit kr rhe
*/

class Solution
{
public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // create a visited array
        vector<int> vis(V, 0);
        // min heap -- pair of distance and node
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 0});
        int sum = 0;
        while (!pq.empty())
        {
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            // if the node is already visited, no need to visit it again
            if (vis[node])
            {
                continue;
            }
            // else visit krlo and distance sum mein add krlo
            vis[node] = 1;
            sum += dis;
            // visit it's adjacent nodes
            for (auto it : adj[node])
            {
                int adjNode = it[0];
                int adjWt = it[1];
                if (!vis[adjNode])
                {
                    pq.push({adjWt, adjNode});
                }
            }
        }
        return sum;
    }
};