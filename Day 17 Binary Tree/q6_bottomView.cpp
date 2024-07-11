class Solution
{
public:
    vector<int> bottomView(Node *root)
    {
        // Your Code Here
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
            mpp[vert] = val;
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