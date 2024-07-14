//jaise binary tree mein krte hai waise krni hai, par yaha inorder 
//given nhi hai, preorder jo given hai usko sort krdo toh inorder mil jayega
//phir same tarike se kr skte hai

class Solution
{
public:
    TreeNode *solve(vector<int> &preorder, vector<int> &inorder, int start, int end, int &idx)
    {
        if (start > end)
        {
            return NULL;
        }
        int i = start;
        int rootVal = preorder[idx];
        for (; i <= end; i++)
        {
            if (inorder[i] == rootVal)
            {
                break;
            }
        }
        idx++;
        TreeNode *root = new TreeNode(rootVal);
        root->left = solve(preorder, inorder, start, i - 1, idx);
        root->right = solve(preorder, inorder, i + 1, end, idx);
        return root;
    }
    TreeNode *bstFromPreorder(vector<int> &preorder)
    {
        vector<int> inorder = preorder;
        sort(inorder.begin(), inorder.end());
        int idx = 0;
        return solve(preorder, inorder, 0, preorder.size() - 1, idx);
    }
};