class Solution
{
public:
    int height(TreeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        int lh = height(root->left);
        int rh = height(root->right);
        if (lh == -1 || rh == -1 || abs(lh - rh) > 1)
        {
            return -1;
        }
        return 1 + max(lh, rh);
    }
    bool isBalanced(TreeNode *root)
    {
        if (root == NULL)
        {
            return true;
        }
        if (height(root) == -1)
        {
            return false;
        }
        return true;
    }
};