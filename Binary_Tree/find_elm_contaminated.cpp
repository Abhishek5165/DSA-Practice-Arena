// Time complexity : O(n);
// Space complexity : O(n);

class FindElements {
public:
    unordered_set<int> st;

    void dfs(TreeNode* root, int val) {
        if (root == NULL) {
            return;
        }
        root->val = val;
        st.insert(val);
        dfs(root->left, 2 * val + 1);
        dfs(root->right, 2 * val + 2);
    }

    FindElements(TreeNode* root) { 
        dfs(root, 0); 
    }
    bool find(int target) { 
        return (st.find(target) != st.end()); 
    }
};