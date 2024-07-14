class Solution
{
public:
    Node *connect(Node *root)
    {
        if (root == NULL)
        {
            return NULL;
        }
        queue<Node *> q;
        q.push(root);
        while (!q.empty())
        {
            int n = q.size();
            for (int i = 0; i < n; i++)
            {
                Node *node = q.front();
                q.pop();
                // agar last node hai toh woh null ko point karegi, else woh next node ko point karegi
                i == n - 1 ? node->next = NULL : node->next = q.front();
                if (node->left)
                {
                    q.push(node->left);
                }
                if (node->right)
                {
                    q.push(node->right);
                }
            }
        }
        return root;
    }
};