// Time Complexity : O(N) + O(N);
// Space Complexity : O(N)+O(N)=O(N);
class Solution {
public:
    int findTime(map<Node*, Node*>& mpp, Node* target) {
      
        int maxxi = 0;
        map<Node*, int> visited;
        queue<Node*> Q;
        Q.push(target);
        visited[target] = 1;

        while (!Q.empty()) {
            int size = Q.size();
            bool flag = false;

            for (int i = 0; i < size; i++) {
                Node* temp = Q.front();
                Q.pop();

                if (temp->left && visited.find(temp->left) == visited.end()) {
                    visited[temp->left] = 1;
                    Q.push(temp->left);
                    flag = true;
                }

                if (temp->right && visited.find(temp->right) == visited.end()) {
                    visited[temp->right] = 1;
                    Q.push(temp->right);
                    flag = true;
                }

                if (mpp.find(temp) != mpp.end() && visited.find(mpp[temp]) == visited.end()) {
                    visited[mpp[temp]] = 1;
                    Q.push(mpp[temp]);
                    flag = true;
                }
            }

            if (flag) {
                maxxi++;
            }
        }
        return maxxi;
    }

    Node* mark(Node* root, map<Node*, Node*>& mpp, int target) {
     
        queue<Node*> Q;
        Q.push(root);
        Node* res = nullptr;

        while (!Q.empty()) {
            Node* temp = Q.front();
            Q.pop();

            if (temp->data == target) {
                res = temp;
            }

            if (temp->left) {
                mpp[temp->left] = temp;
                Q.push(temp->left);
            }

            if (temp->right) {
                mpp[temp->right] = temp;
                Q.push(temp->right);
            }
        }
        return res;
    }

    int minTime(Node* root, int target) {
        map<Node*, Node*> mpp;
        Node* node = mark(root, mpp, target);
        return findTime(mpp, node);
    }
};
