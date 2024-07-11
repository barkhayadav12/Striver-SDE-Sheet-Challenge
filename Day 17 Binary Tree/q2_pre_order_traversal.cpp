class Solution
{
public:
    void pre_order(TreeNode *root, vector<int> &op)
    {
        if (root == NULL)
        {
            return;
        }
        op.push_back(root->val);
        pre_order(root->left, op);
        pre_order(root->right, op);
    }
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> op;
        pre_order(root, op);
        return op;
    }
};