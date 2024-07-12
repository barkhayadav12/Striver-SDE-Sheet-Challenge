class Solution
{
public:
    bool isLeaf(Node *root)
    {
        if (root->left == NULL && root->right == NULL)
        {
            return true;
        }
        return false;
    }
    void leftNodes(Node *root, vector<int> &v)
    {
        if (root == NULL)
        {
            return;
        }
        if (!isLeaf(root))
        {
            v.push_back(root->data);
        }
        if (root->left)
        {
            leftNodes(root->left, v);
        }
        else
        {
            leftNodes(root->right, v);
        }
    }
    void addLeaf(Node *root, vector<int> &v)
    {
        if (root == NULL)
        {
            return;
        }
        if (isLeaf(root))
        {
            v.push_back(root->data);
        }
        if (root->left)
        {
            addLeaf(root->left, v);
        }
        if (root->right)
        {
            addLeaf(root->right, v);
        }
    }
    void rightNodes(Node *root, vector<int> &v)
    {
        vector<int> temp;
        Node *curr = root;
        while (curr)
        {
            if (!isLeaf(curr))
            {
                temp.push_back(curr->data);
            }
            if (curr->right)
            {
                curr = curr->right;
            }
            else
            {
                curr = curr->left;
            }
        }
        for (int i = temp.size() - 1; i >= 0; i--)
        {
            v.push_back(temp[i]);
        }
    }
    vector<int> boundary(Node *root)
    {
        // Your code here
        vector<int> v;
        if (!isLeaf(root))
        {
            v.push_back(root->data);
        }
        leftNodes(root->left, v);
        addLeaf(root, v);
        rightNodes(root->right, v);
        return v;
    }
};