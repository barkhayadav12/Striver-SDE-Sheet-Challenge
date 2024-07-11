class Solution
{
public:
    void post_order(TreeNode *root, vector<int> &op)
    {
        if (root == NULL)
        {
            return;
        }
        post_order(root->left, op);
        post_order(root->right, op);
        op.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> op;
        post_order(root, op);
        return op;
    }
};