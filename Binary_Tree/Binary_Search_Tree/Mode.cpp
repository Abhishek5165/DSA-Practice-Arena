
// Approch - 1

// time complexity : O(N);
// space complexity : O(N);


class Solution {
public:
    void solve(TreeNode* root,unordered_map<int,int>&mpp){

    if(root == NULL){
    return;
    }
    solve(root->left,mpp);
    mpp[root->val]++;
    solve(root->right,mpp);
    }
    vector<int> findMode(TreeNode* root) {

    unordered_map<int,int>mpp;
    solve(root,mpp);

    vector<int>result;
    int count = 0;

    for(auto &it : mpp){
    
    if(it.second > count){
    count = it.second;
    result = {};
    result.push_back(it.first);
    }
    else if(it.second == count){
    result.push_back(it.first);
    }
    }   
    return result;
    }
};


// Approch - 2

// time complexity : O(N);
// space complexity : O(1);

// Using only constant space O(1) follow up Question

class Solution {
public:
    vector<int> result;
    int currNumber = 0;
    int currFreq = 0;
    int maxFreq = 0;

    void solve(TreeNode* root) {

        if (!root)
            return;

        solve(root->left);

        if (root->val == currNumber) {
            currFreq++;
        } 
        else {
            currNumber = root->val;
            currFreq = 1;
        }
        if(currFreq > maxFreq) {
            maxFreq = currFreq;
            result = {};
        }
        if(currFreq == maxFreq) {
            result.push_back(root->val);
        }
        solve(root->right);
    }

    vector<int> findMode(TreeNode* root) {

        solve(root);
        return result;
    }
};