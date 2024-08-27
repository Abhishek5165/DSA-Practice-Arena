// Time Complexity:

// Average Case: O(logn)
// Worst Case: O(n)

// Space Complexity: O(1)

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* temp = root;

        if (temp == NULL) {
            return new TreeNode(val);
        }
        while (true) {
            if (temp->val <= val) {
                if (temp->right != NULL) {
                    temp = temp->right;
                } else {
                    temp->right = new TreeNode(val);
                    break;
                }
            } 
            else {
                if (temp->left != NULL) {
                    temp = temp->left;
                }
                else{
                temp->left = new TreeNode(val);
                break;
                }
            }
        }
        return root;
    }
};