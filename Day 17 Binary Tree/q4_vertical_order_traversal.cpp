class Solution
{
public:
    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        vector<vector<int>> res;
        if (root == NULL)
        {
            return res;
        }
        map<int, map<int, multiset<int>>> mpp;
        queue<pair<TreeNode *, pair<int, int>>> q;
        q.push({root, {0, 0}});
        while (!q.empty())
        {
            auto temp = q.front();
            q.pop();
            int vert = temp.second.first;
            int level = temp.second.second;
            TreeNode *node = temp.first;
            mpp[vert][level].insert(node->val);
            if (node->left)
            {
                q.push({node->left, {vert - 1, level + 1}});
            }
            if (node->right)
            {
                q.push({node->right, {vert + 1, level + 1}});
            }
        }
        for (auto it : mpp)
        {
            vector<int> col;
            for (auto q : it.second)
            {
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            res.push_back(col);
        }
        return res;
    }
};