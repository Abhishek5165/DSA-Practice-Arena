// Time Complexity : O(n)
// Space Complexity : O(n)

vector<int> levelOrder(TreeNode<int> *root)
{
    vector<int> ans;

    if (root == NULL)
    {
        return ans;
    }
    queue<TreeNode<int> *> Q;
    Q.push(root);

    while (!Q.empty())
    {
        int size = Q.size();
        for (int i = 0; i < size; i++)
        {
            root = Q.front();
            Q.pop();
            ans.push_back(root->data);

            if (root->left != NULL)
            {
                Q.push(root->left);
            }
            if (root->right != NULL)
            {
                Q.push(root->right);
            }
        }
    }
    return ans;
}
