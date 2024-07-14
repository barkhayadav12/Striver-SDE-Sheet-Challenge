class Solution
{
public:
    bool isValid(TreeNode *root, long long minRange, long long maxRange)
    {
        if (root == NULL)
        {
            return true;
        }
        if (root->val >= maxRange || root->val <= minRange)
        {
            return false;
        }
        return isValid(root->left, minRange, root->val) && isValid(root->right, root->val, maxRange);
    }
    bool isValidBST(TreeNode *root)
    {
        long long int min = -1000000000000, max = 1000000000000;
        return isValid(root, min, max);
    }
};