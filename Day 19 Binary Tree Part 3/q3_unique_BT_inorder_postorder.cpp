class Solution
{
public:
    TreeNode *solve(vector<int> &inorder, vector<int> &postorder, int inStart, int inEnd, int postStart, int postEnd)
    {
        if (inStart > inEnd)
        {
            return NULL;
        }
        // root ki value postEnd hogi
        TreeNode *root = new TreeNode(postorder[postEnd]);
        int i = inStart;
        for (; i <= inEnd; i++)
        {
            if (inorder[i] == root->val) // i kin value mil gayi
            {
                break;
            }
        }
        // i ke left mein jo hai woh new binary tree ke left nodes honge
        // i ke right mein jo hai woh new binary tree ka right nodes hoga
        // left mein kitne nodes honge? i-inStart
        // right mein kitne nodes honge? inEnd-i
        int leftSize = i - inStart;
        int rightSize = inEnd - i;
        root->left = solve(inorder, postorder, inStart, i - 1, postStart, postStart + leftSize - 1);
        root->right = solve(inorder, postorder, i + 1, inEnd, postEnd - rightSize, postEnd - 1);
        return root;
    }
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        int n = inorder.size();
        return solve(inorder, postorder, 0, n - 1, 0, n - 1);
    }
};