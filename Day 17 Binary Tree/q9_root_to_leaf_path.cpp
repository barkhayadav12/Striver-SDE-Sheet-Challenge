class Solution
{
public:
    void solve(vector<vector<int>> &ans, vector<int> &v, Node *root)
    {
        if (root == NULL)
        {
            return;
        }
        v.push_back(root->data);
        if (root->left == NULL && root->right == NULL)
        {
            ans.push_back(v);
        }
        solve(ans, v, root->left);
        solve(ans, v, root->right);
        v.pop_back();
    }
    vector<vector<int>> Paths(Node *root)
    {
        // code here
        vector<int> v;
        vector<vector<int>> ans;
        solve(ans, v, root);
        return ans;
    }
};