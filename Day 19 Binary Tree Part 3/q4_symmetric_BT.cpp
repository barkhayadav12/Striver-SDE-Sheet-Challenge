class Solution
{
public:
    bool sym(TreeNode *p, TreeNode *q)
    {
        if (p == NULL && q == NULL)
        {
            return true;
        }
        if (p == NULL || q == NULL)
        {
            return false;
        }
        return (p->val == q->val) && sym(p->left, q->right) && sym(p->right, q->left);
    }
    bool isSymmetric(TreeNode *root)
    {
        if (root == NULL)
        {
            return true;
        }
        return sym(root->left, root->right);
    }
};