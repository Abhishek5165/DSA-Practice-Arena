// Using DFS(stack) of Tree.

// Time complexity : O(n);
// Space complexity : O(n);

class Solution {
public:
    int maxDepth(TreeNode* root) {
    if(root == NULL){
    return 0;
    }

    stack<pair<TreeNode*,int>>st;
    st.push({root,1});
    int depth = 0;

    while(!st.empty()){

    auto it = st.top();
    st.pop();

    TreeNode* node = it.first;
    int H = it.second;

    if(node != NULL){
    depth = max(depth,H);
    st.push({node->left,H+1});
    st.push({node->right,H+1});
    }
    }
    return depth;
    }
};


// using Recursion ...
// Time complexity : O(n);
// Space complexity : O(n);


class Solution {
public:
    int maxDepth(TreeNode* root) {
    if(root == NULL){
    return 0;
    } 
    int Left = maxDepth(root->left);
    int Right = maxDepth(root->right);
    return 1 + max(Left,Right);
    }
};

// using BFS of Tree (using queue) ...
// Time complexity : O(n);
// Space complexity : O(n);


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
   int maxDepth(TreeNode* root) {
        queue<TreeNode*> q;
        if (root != nullptr) {
            q.push(root);
        }

        int level = 0;

        while (!q.empty()) {
            int size = q.size();

            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                if (node->left != nullptr) {
                    q.push(node->left);
                }
                if (node->right != nullptr) {
                    q.push(node->right);
                }
            }
            level++;
        }
        return level;
   }
};
