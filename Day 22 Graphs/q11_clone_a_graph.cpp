class Solution
{
public:
    Node *cloneGraph(Node *node)
    {
        if (node == NULL)
        {
            return NULL;
        }
        unordered_map<Node *, Node *> mpp;
        queue<Node *> q;
        Node *copy = new Node(node->val, {});
        mpp[node] = copy;
        q.push(node);
        while (!q.empty())
        {
            Node *curr = q.front();
            q.pop();
            for (auto it : curr->neighbors)
            {
                // neighbor agar hai toh already visit kr liya hai kya check kr rhe, agar
                // nhi kiya hai toh new node bana denge and queue mein push krdenge
                if (mpp.find(it) == mpp.end())
                {
                    Node *neighbor = new Node(it->val, {});
                    mpp[it] = neighbor;
                    q.push(it);
                }
                // connect kr rhe current node and neighbor ko
                mpp[curr]->neighbors.push_back(mpp[it]);
            }
        }
        return copy;
    }
};