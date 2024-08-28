// Time Complexity : O(N)
// Space Complexity : O(H)*2;

class BST_iterator {
    stack<TreeNode*> MyStack;
    bool reverse = true;

    public:
    BST_iterator(TreeNode* root, bool isReverse) {
        reverse = isReverse;
        pushALL(root);
    }
    bool HashNext() { return !MyStack.empty(); }

    int next() {
        TreeNode* tempNode = MyStack.top();
        MyStack.pop();

        if (reverse != true) {
            pushALL(tempNode->right);
        } else {
            pushALL(tempNode->left);
        }
        return tempNode->val;
    }

private:
    void pushALL(TreeNode* node) {
        while(node != NULL) {
            MyStack.push(node);
            if (reverse == true) {
                node = node->right;
            } else {
                node = node->left;
            }
        }
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if (root == NULL) {
            return false;
        }

        BST_iterator N(root, false);
        BST_iterator B(root, true);

        int i = N.next();
        int j = B.next();

        while (i < j) {
            if (i + j == k) {
                return true;
            } else if (i + j < k) {
                i = N.next();
            } else {
                j = B.next();
            }
        }
        return false;
    }
};