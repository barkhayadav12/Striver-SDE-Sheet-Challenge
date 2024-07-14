class Solution
{
public:
    TreeNode *insert(int lo, int hi, vector<int> &nums)
    {
        if (lo >= hi)
        {
            return NULL;
        }
        int mid = lo + (hi - lo) / 2;
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = insert(lo, mid, nums);
        root->right = insert(mid + 1, hi, nums);
        return root;
    }
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        if (nums.size() <= 0)
        {
            return NULL;
        }
        return insert(0, nums.size(), nums);
    }
};