// using Recursion ......

// Time Complexity : O(n)
// Space Complexity : O(n)

void Inorder(TreeNode *root,vector<int>&I){

    if(root==NULL){
        return;
    }
    Inorder(root->left,I);
    I.push_back(root->data);
    Inorder(root->right,I);

}
vector<int> getInOrderTraversal(TreeNode *root)
{
    vector<int>I;
    Inorder(root,I);
    return I;
}

// Time Complexity : O(n)
// Space Complexity : O(n)

// using stack ......

#include<bits/stdc++.h>

vector<int> getInOrderTraversal(TreeNode *root)
{
    vector<int>ans;

    if(root == NULL){
    return ans;
    }
    stack<TreeNode*>st;
    
    TreeNode* temp = root;

    while(true){

    while(temp != NULL){

    st.push(temp);
    temp = temp->left;
    }
    if(st.empty() == true) break;
    
    temp = st.top();
    st.pop();
    
    ans.push_back(temp->data);
    temp = temp->right;
    }
    return ans;
}