class Solution
{
public:
    int maxSum(TreeNode *root, int &sum)
    {
        if (root == NULL)
        {
            return 0;
        }
        int lh = max(maxSum(root->left, sum), 0);
        int rh = max(maxSum(root->right, sum), 0);
        sum = max(sum, lh + rh + root->val);
        return root->val + max(lh, rh);
    }
    int maxPathSum(TreeNode *root)
    {
        int sum = INT_MIN;
        maxSum(root, sum);
        return sum;
    }
};