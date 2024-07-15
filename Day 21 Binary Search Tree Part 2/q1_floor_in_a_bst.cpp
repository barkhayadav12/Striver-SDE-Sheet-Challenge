// value that is smaller than or equal to x
int floorInBST(TreeNode<int> *root, int X)
{
    // Write your code here.
    int ans = -1;
    while (root != NULL)
    {
        if (root->val == X)
        {
            return root->val;
        }
        else if (root->val > X)
        {
            root = root->left;
        }
        else
        {
            ans = root->val;
            root = root->right;
        }
    }
    return ans;
}