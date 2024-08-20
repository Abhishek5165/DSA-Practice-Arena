// Time complexity : O(n)
// Space complexity : O(n)

// Approch - 1 Using DFS 

class Solution {
public:
    TreeNode* solve(TreeNode* root, int val, int depth, int curr) {

        if (root == NULL) {
            return NULL;
        }
        if (depth == 1) {

            TreeNode* newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        }
        if (curr == depth - 1) {

            TreeNode* tempLeft = root->left;
            TreeNode* tempRight = root->right;

            TreeNode* newLeft = new TreeNode(val);
            TreeNode* newRight = new TreeNode(val);

            root->left = newLeft;
            root->right = newRight;

            newLeft->left = tempLeft;
            newRight->right = tempRight;
        }
        root->left = solve(root->left, val, depth, curr + 1);
        root->right = solve(root->right, val, depth, curr + 1);

        return root;
    }

    TreeNode* addOneRow(TreeNode* root, int val, int depth) {

        int curr = 1;
        root = solve(root, val, depth, curr);
        return root;
    }
};

// Time complexity : O(n)
// Space complexity : O(n)

// Approch - 2 Using BFS 

class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if(d == 1) {
            TreeNode* newRoot = new TreeNode(v);
            newRoot->left = root;
            return newRoot;
        }
        queue<TreeNode*> que;
        
        que.push(root);
        int level = 0;
        bool rowAdded = false;
        while(!que.empty()) {
            int n = que.size();
            level++;
            while(n--) {
                TreeNode* curr = que.front();
                que.pop();
                TreeNode* tempL = curr->left;
                TreeNode* tempR = curr->right;
                if(level == d-1) {
                    curr->left  = new TreeNode(v);
                    curr->right = new TreeNode(v);
                    curr->left->left   = tempL;
                    curr->right->right = tempR;
                    rowAdded = true;
                }
                if(tempL)
                    que.push(tempL);
                if(tempR)
                    que.push(tempR);
            }
            if(rowAdded)
                break;
        }
        
        return root;
    }
};