// Time complexity : O(n);
// Space complexity : O(n);

class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {

        if (root == NULL) {
            return -1;
        }
        priority_queue<long long> pq;

        queue<TreeNode*> Q;
        Q.push(root);

        while (!Q.empty()) {

            long long sum = 0;
            int size = Q.size();

            while (size--) {

                TreeNode* temp = Q.front();
                Q.pop();
                sum += temp->val;

                if (temp->left) {
                    Q.push(temp->left);
                }
                if (temp->right) {
                    Q.push(temp->right);
                }
            }
            pq.push(sum);
        }

        if (pq.size() < k) {
            return -1;
        }
        while (--k > 0) {
            pq.pop();
        }
        return pq.top();
    }
};