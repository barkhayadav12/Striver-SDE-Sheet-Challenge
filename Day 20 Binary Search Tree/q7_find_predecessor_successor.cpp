class Solution
{
public:
    // predecessor woh hai jo target just smaller hai
    // successor woh hai jo target se just greater hai
    void findPreSuc(Node *root, Node *&pre, Node *&suc, int key)
    {
        // Your code goes here
        if (root == NULL)
        {
            return;
        }
        if (root->key > key)
        {
            suc = root;
            findPreSuc(root->left, pre, suc, key);
        }
        else if (root->key < key)
        {
            pre = root;
            findPreSuc(root->right, pre, suc, key);
        }
        else
        {
            findPreSuc(root->right, pre, suc, key);
            findPreSuc(root->left, pre, suc, key);
        }
    }
};