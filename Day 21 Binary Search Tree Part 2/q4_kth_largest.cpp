// return the Kth largest element in the given BST rooted at 'root'
class Solution
{
public:
    void findLargest(Node *root, int target, int &ans, int &cnt)
    {
        if (root == NULL)
        {
            return;
        }
        findLargest(root->right, target, ans, cnt);
        cnt++;
        if (cnt == target)
        {
            ans = root->data;
            return;
        }
        findLargest(root->left, target, ans, cnt);
    }
    int kthLargest(Node *root, int K)
    {
        // Your code here
        int cnt = 0;
        int ans = 0;
        findLargest(root, K, ans, cnt);
        return ans;
    }
};