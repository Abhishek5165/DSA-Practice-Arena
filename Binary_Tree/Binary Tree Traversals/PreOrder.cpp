// Time Complexity : O(n)
// Space Complexity : O(n)

// using Recursion ......

#include <bits/stdc++.h>

void Preorder(TreeNode<int> *root, vector<int> &ans)
{

    if (root == NULL)
    {
        return;
    }
    ans.push_back(root->data);
    Preorder(root->left, ans);
    Preorder(root->right, ans);
}
vector<int> preOrder(TreeNode<int> *root)
{

    vector<int> ans;
    Preorder(root, ans);
    return ans;
}

// Time Complexity : O(n)
// Space Complexity : O(n)

// using one stack ....

#include <bits/stdc++.h>

vector<int> preOrder(TreeNode<int> *root)
{

    vector<int> ans;

    if (root == NULL)
    {
        return ans;
    }
    stack<TreeNode<int> *> st;
    st.push(root);

    while (!st.empty())
    {

        TreeNode<int> *temp = st.top();
        st.pop();

        ans.push_back(temp->data);

        if (temp->right != NULL)
        {
            st.push(temp->right);
        }
        if (temp->left != NULL)
        {
            st.push(temp->left);
        }
    }
    return ans;
}
