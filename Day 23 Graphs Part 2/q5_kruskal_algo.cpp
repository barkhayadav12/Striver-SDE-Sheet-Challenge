public:
    vector<int> parent;
    vector<int> size;
    DisjointSet(int n)
    {
        parent.resize(n + 1);
        size.resize(n + 1);
        // initially har node ka parent the node itself hoti hai
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
        // initially sab ki size 1 hai
        for (int i = 0; i <= n; i++)
        {
            size[i] = 1;
        }
    }

    // find parent
    int findParent(int node)
    {
        if (node == parent[node])
        {
            return node;
        }
        return parent[node] = findParent(parent[node]);
    }
    // union of two nodes
    void unionBySize(int u, int v)
    {
        int ultimate_parent_of_u = findParent(u);
        int ultimate_parent_of_v = findParent(v);
        // if ultimate parent same hai toh, koi connection krne ki jarurat nhi hai, because woh same graph ke nodes hai
        if (ultimate_parent_of_u == ultimate_parent_of_v)
        {
            return;
        }
        // agar that two nodes same component ke nhi hai toh, jis component ka size bada hai usmein
        // connect krdo
        if (ultimate_parent_of_u > ultimate_parent_of_v)
        {
            parent[ultimate_parent_of_v] = ultimate_parent_of_u;
            size[ultimate_parent_of_u] += size[ultimate_parent_of_v];
        }
        else
        {
            parent[ultimate_parent_of_u] = ultimate_parent_of_v;
            size[ultimate_parent_of_v] += size[ultimate_parent_of_u];
        }
    }
};
class Solution
{
public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // initially input aise given thi 0 ->{1,2}, humne iss form mein convert krdi {0,{1,2}}
        vector<pair<int, pair<int, int>>> edges;
        for (int i = 0; i < V; i++)
        {
            for (auto it : adj[i])
            {
                int node = i;
                int adjNode = it[0];
                int wt = it[1];
                edges.push_back({wt, {node, adjNode}});
            }
        }
        // sort krdi according to weight
        sort(edges.begin(), edges.end());
        int sum = 0;
        DisjointSet ds(V);
        for (auto it : edges)
        {
            int wt = it.first;
            int u = it.second.first;
            int v = it.second.second;
            // if ultimate parent same hai toh iska mtlb hai ki u and v already connected hai and they belong to
            // the same component, jab same nhi hai toh they belong to different component and humein unko connect
            // krna hai, since humne sort krdi hai so jo lesser wt wale honge usko pehle connect kr diya jayega
            if (ds.findParent(u) != ds.findParent(v))
            {
                sum += wt;
                ds.unionBySize(u, v);
            }
        }
        return sum;
    }
};