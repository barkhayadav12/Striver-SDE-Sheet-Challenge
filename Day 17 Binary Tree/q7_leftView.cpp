void leftView(vector<int> &ans, Node *root, int level)
{
    if (root == NULL)
    {
        return;
    }
    if (ans.size() == level)
    {
        ans.push_back(root->data);
    }
    leftView(ans, root->left, level + 1);
    leftView(ans, root->right, level + 1);
}
vector<int> leftView(Node *root)
{
    // Your code here
    vector<int> ans;
    if (root == NULL)
    {
        return ans;
    }
    leftView(ans, root, 0);
    return ans;
}
