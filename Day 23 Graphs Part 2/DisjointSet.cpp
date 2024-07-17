/*
The disjoint Set data structure is generally used for dynamic graphs.
A dynamic graph generally refers to a graph that keeps on changing its configuration

Two Functionalites:
1. Finding the parent
    : if two nodes have the same ultimate parent, they belong to the same component else they belong to different component
2. Union
     : union by rank
     : union by size
*/

class DisjointSet
{
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
