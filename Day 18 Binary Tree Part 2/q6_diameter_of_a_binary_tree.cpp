class Solution
{
public:
    int maxPath(TreeNode *root, int &sum)
    {
        if (root == NULL)
        {
            return 0;
        }
        int lh = maxPath(root->left, sum);
        int rh = maxPath(root->right, sum);
        sum = max(sum, lh + rh);
        return 1 + max(lh, rh);
    }
    int diameterOfBinaryTree(TreeNode *root)
    {
        int sum = 0;
        maxPath(root, sum);
        return sum;
    }
};