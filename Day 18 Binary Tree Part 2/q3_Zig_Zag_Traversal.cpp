class Solution
{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> res;
        if (root == NULL)
        {
            return res;
        }
        queue<TreeNode *> q;
        q.push(root);
        bool leftToRight = true;
        while (!q.empty())
        {
            int n = q.size();
            vector<int> v(n);
            for (int i = 0; i < n; i++)
            {
                TreeNode *temp = q.front();
                q.pop();
                int index = leftToRight ? i : (n - 1 - i);
                v[index] = temp->val;
                if (temp->left)
                {
                    q.push(temp->left);
                }
                if (temp->right)
                {
                    q.push(temp->right);
                }
            }
            leftToRight = !leftToRight;
            res.push_back(v);
        }
        return res;
    }
};