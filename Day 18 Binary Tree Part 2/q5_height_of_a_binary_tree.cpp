class Solution
{
public:
    int maxDepth(TreeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        int x = maxDepth(root->left);
        int y = maxDepth(root->right);
        return 1 + max(x, y);
    }
};