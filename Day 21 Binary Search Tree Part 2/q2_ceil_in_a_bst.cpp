// greater than or equal to x
int findCeil(BinaryTreeNode<int> *node, int x)
{
    // Write your code here.
    int ans = -1;
    while (node != NULL)
    {
        if (node->data == x)
        {
            return node->data;
        }
        else if (node->data > x)
        {
            ans = node->data;
            node = node->left;
        }
        else
        {
            node = node->right;
        }
    }
    return ans;
}