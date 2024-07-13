class Solution
{
public:
    TreeNode *solve(vector<int> &preorder, vector<int> &inorder, int start, int end, int &idx)
    {
        if (start > end)
        {
            return NULL;
        }
        // preorder ka pehla wala is the root aur uski index idx mann rhe
        // root ko abhi inorder mein dhundhna hai and uski index i mann rhe
        // jo i ke left mein hai woh jo new binary tree hai uska left nodes hoga
        // and jo i ke baad aata hai woh new binary tree ka right nodes honge
        int rootVal = preorder[idx];
        int i = start;
        for (; i <= end; i++)
        {
            if (inorder[i] == rootVal) // i ki value mil gayi
            {
                break;
            }
        }
        idx++;
        TreeNode *root = new TreeNode(rootVal);
        // start to i-1 left nodes honge
        root->left = solve(preorder, inorder, start, i - 1, idx);
        // i+1 to end right nodes honge
        root->right = solve(preorder, inorder, i + 1, end, idx);
        return root;
    }
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        int n = preorder.size();
        int idx = 0;
        return solve(preorder, inorder, 0, n - 1, idx);
    }
};