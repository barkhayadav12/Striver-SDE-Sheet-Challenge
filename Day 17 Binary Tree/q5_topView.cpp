class Solution
{
public:
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        //[vertical,node value]
        map<int, int> mpp;
        //{node, vertical}
        queue<pair<Node *, int>> q;
        vector<int> ans;
        q.push({root, 0});
        while (!q.empty())
        {
            auto it = q.front();
            q.pop();
            Node *temp = it.first;
            int val = temp->data;
            int vert = it.second;
            if (mpp.find(vert) == mpp.end())
            {
                mpp[vert] = val;
            }
            if (temp->left)
            {
                q.push({temp->left, vert - 1});
            }
            if (temp->right)
            {
                q.push({temp->right, vert + 1});
            }
        }
        for (auto it : mpp)
        {
            ans.push_back(it.second);
        }
        return ans;
    }
};