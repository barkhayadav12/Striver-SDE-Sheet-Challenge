class Solution
{
public:
    void find(TreeNode *root, int k, int &ans, int &cnt)
    {
        if (root == NULL)
        {
            return;
        }
        find(root->left, k, ans, cnt);
        cnt++;
        if (cnt == k)
        {
            ans = root->val;
            return;
        }
        find(root->right, k, ans, cnt);
    }
    int kthSmallest(TreeNode *root, int k)
    {
        int ans;
        int cnt = 0;
        find(root, k, ans, cnt);
        return ans;
    }
};