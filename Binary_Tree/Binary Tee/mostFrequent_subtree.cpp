// Time Complexity : O(n*n)
// Space Complexity : O(n)

// Approch - 1 Brute Force 

class Solution {
private:
    int subTreeSum(TreeNode* root)
    {
        if(root==NULL)
            return 0;
        
        return root->val+subTreeSum(root->left)+subTreeSum(root->right);
    }
    void traverseTree(TreeNode* root, unordered_map<int,int>& mp)
    {
        if(root==NULL)
            return;
        
        mp[subTreeSum(root)]++;

        traverseTree(root->left, mp);
        traverseTree(root->right, mp);
    }
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        
        unordered_map<int,int> mp;
        vector<int> ans;

        traverseTree(root, mp);

        int maxi=0;
        for(auto it:mp)
            maxi = max(maxi, it.second);
        
        for(auto it:mp)
            if(it.second==maxi)
                ans.push_back(it.first);
        
        return ans;
    }
};

// Approch - 2 using Bottom to top 

// Time Complexity : O(n)
// Space Complexity : O(n)

class Solution {
public:

    unordered_map<int,int> mpp;
    int count=0;
    int findSum(TreeNode* &root){

    if(root == NULL){
    return 0;
    }
    int left = findSum(root->left);
    int right = findSum(root->right);

    int sum = left + right + root->val;
    mpp[sum]++;
    count = max(count,mpp[sum]);
    return sum;
    }

    vector<int> findFrequentTreeSum(TreeNode* root) {
        
    vector<int>ans;
    if(root == NULL){
    return ans;
    }

    findSum(root);

    for(auto it:mpp){

    if(it.second == count){
    ans.push_back(it.first);
    }
    }
    return ans;
    }
};

