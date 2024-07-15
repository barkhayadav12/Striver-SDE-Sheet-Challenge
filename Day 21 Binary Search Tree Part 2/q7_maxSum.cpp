/*
Postorder traversal use kr rhe
*/

int ans;
class NodeValue
{
public:
    int maxNode, minNode, maxSum;
    NodeValue(int minNode, int maxNode, int maxSum)
    {
        this->minNode = minNode;
        this->maxNode = maxNode;
        this->maxSum = maxSum;
    }
};
class Solution
{
public:
    NodeValue calSum(TreeNode *root)
    {
        if (root == NULL)
        {
            return NodeValue(INT_MAX, INT_MIN, 0);
        }
        auto left = calSum(root->left);
        auto right = calSum(root->right);
        if (left.maxNode < root->val && root->val < right.minNode)
        {
            ans = max(ans, left.maxSum + right.maxSum + root->val);
            return NodeValue(min(root->val, left.minNode), max(root->val, right.maxNode), left.maxSum + right.maxSum + root->val);
        }
        return NodeValue(INT_MIN, INT_MAX, max(left.maxSum, right.maxSum));
    }
    int maxSumBST(TreeNode *root)
    {
        ans = 0;
        calSum(root);
        return ans > 0 ? ans : 0;
    }
};