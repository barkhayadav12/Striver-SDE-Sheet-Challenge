/*
Bellman Ford Algorithm:

It is an algorithm to find the shortest path. Dijkstra algo also did the same job
but dijkstra algo can't can be used if there are negative edges and if there is a negative cycle.

Important point: It is applicable to directed graph only, so if an undirected graph is given, pehle convert it to a 
directed graph

Negative cycle : if the overall path weight ka sum comes out to be negative, then there is a negative cycle.

How does it work?

We are making n-1 iterations and we are checking, suppose there is an edge between u and v,
toh hum check kr rhe ki dist[u]+edgeWt( jo edge weight u and v ke beech hai ) (dist[u] mtlb source se u tak aane ki distance)
lesser hai kya dist[v] se (dist[v] mtlb source se v tak ki distance), agar hai toh hum distances ko update kr rhe hai

why n-1 iteration?

Suppose you have a graph of this form 0->1->2->3 like this,
toh jab hum check kr rhe honge distances, tab pehle ek iteration mein ek
distance update ho rhi hai, aur next iteration mein ek aur distance update hongi, and so on

Yeh worst case hai, worst case mein n-1 iterations krne pad jayenge saare distances ko update hone mein
kyunki adjacent nodes uske pehle wale node pe dependent hai, jab pehle wale ki shortest distance milega tabhi hum compare kr
payenge and distance tab update ho payegi

Checking for negative cycle?

Agar negative cycle present hogi graph mein, negative cycle mein har iteration ke baad total path weight ka sum decrease hote jaata
hai, so after that n-1 iteration humko source se un particular nodes tak ka shortest distance mil chuki hai, par agar graph mein kahi pe
negative cycle present hogi toh nth iteration jab hum kr rhe honge tab phir distance update ho rhi hogi, agar aisa update krne
wala situation aata hai toh hum conclude karenge ki negative cycle present hai graph mein
*/

class Solution
{
public:
    /*  Function to implement Bellman Ford
     *   edges: vector of vectors which represents the graph
     *   S: source vertex to start traversing graph with
     *   V: number of vertices
     */
    vector<int> bellman_ford(int V, vector<vector<int>> &edges, int S)
    {
        // need to make n-1, where n is the number of nodes iterations
        // create a distance array
        vector<int> dist(V, 1e8);
        dist[S] = 0;
        for (int i = 0; i < V - 1; i++)
        {
            for (auto it : edges)
            {
                int node = it[0];
                int adjNode = it[1];
                int adjWt = it[2];
                if (dist[node] + adjWt < dist[adjNode] && dist[node] != 1e8)
                {
                    dist[adjNode] = dist[node] + adjWt;
                }
            }
        }
        // checking if there is a negative cycle
        for (auto it : edges)
        {
            int node = it[0];
            int adjNode = it[1];
            int adjWt = it[2];
            if (dist[node] + adjWt < dist[adjNode] && dist[node] != 1e8)
            {
                return {-1};
            }
        }
        return dist;
    }
};