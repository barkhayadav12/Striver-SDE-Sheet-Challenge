class Solution
{
public:
    void level_order(TreeNode *root, vector<vector<int>> &res)
    {
        if (root == NULL)
        {
            return;
        }
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            int n = q.size();
            vector<int> v;
            for (int i = 0; i < n; i++)
            {
                TreeNode *temp = q.front();
                q.pop();
                v.push_back(temp->val);
                if (temp->left)
                {
                    q.push(temp->left);
                }
                if (temp->right)
                {
                    q.push(temp->right);
                }
            }
            res.push_back(v);
        }
    }
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> res;
        level_order(root, res);
        return res;
    }
};