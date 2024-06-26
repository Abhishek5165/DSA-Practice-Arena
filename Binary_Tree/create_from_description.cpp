// time complexity : O(n);
// space complexity : O(n);

class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {

    int n = descriptions.size();

    unordered_map<int, TreeNode*> mpp;
    unordered_map<int, int> parent, child;

    for (int i = 0; i < n; i++) {

        if (mpp.find(descriptions[i][0]) == mpp.end()) {

            TreeNode* parent_node = new TreeNode(descriptions[i][0]);
                mpp[descriptions[i][0]] = parent_node;
        }
        if (mpp.find(descriptions[i][1]) == mpp.end()) {

            TreeNode* child_node = new TreeNode(descriptions[i][1]);
                mpp[descriptions[i][1]] = child_node;
        }

        if (descriptions[i][2] == 1) {
            mpp[descriptions[i][0]]->left = mpp[descriptions[i][1]];
        } 
        else {
            mpp[descriptions[i][0]]->right = mpp[descriptions[i][1]];
        }
        parent[descriptions[i][0]]++;
        child[descriptions[i][1]]++;
        }
        
        TreeNode* root;

        for (auto it : mpp) {

            if (parent.find(it.first) != parent.end() &&
                child.find(it.first) == child.end()) {

                root = it.second;
                break;
            }
        }
        return root;
    }
};