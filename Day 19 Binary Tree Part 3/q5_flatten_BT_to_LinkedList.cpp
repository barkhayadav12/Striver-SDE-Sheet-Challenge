class Solution
{
public:
    void flatten(TreeNode *root)
    {
        if (root == NULL)
        {
            return;
        }
        stack<TreeNode *> stk;
        stk.push(root);
        while (!stk.empty())
        {
            TreeNode *curr = stk.top();
            stk.pop();
            if (curr->right)
            {
                stk.push(curr->right);
            }
            if (curr->left)
            {
                stk.push(curr->left);
            }
            if (!stk.empty())
            {
                curr->right = stk.top();
                curr->left = NULL;
            }
        }
    }
};