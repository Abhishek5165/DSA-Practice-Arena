// Time Complexity : O(N*N)
// Space Complexity : O(N)

class Solution {
public:

    int maxu(vector<int>&nums,int s,int e){

    int index = -1;
    int maxxi = INT_MIN;

    for(int i=s;i<= e;i++){
    if(maxxi < nums[i]){
    maxxi = nums[i];
    index = i;
    }
    }
    return index;
    }
    
    TreeNode* build_Tree(vector<int>&nums,int start,int end){
     
    if(start > end){
    return NULL;
    }
    if(start == end){
    TreeNode* newNode = new TreeNode(nums[start]);
    return newNode;
    }

    int index = maxu(nums,start,end);
    TreeNode* root = new TreeNode(nums[index]);
    root->left = build_Tree(nums,start,index-1);
    root->right = build_Tree(nums,index+1,end);

    return root;
    }

    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
    int high = nums.size()-1;
    TreeNode* root = build_Tree(nums,0,high);
    return root;
    }
};



// Approch - 2 using Stack 

// Time complexity : O(N)
// Space complexity : O(N)

class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        stack<TreeNode*> st;

        for(int i = 0; i < nums.size(); i++) {
            TreeNode* node = new TreeNode(nums[i]);
            while(!st.empty() && st.top() -> val < nums[i]) {
                node -> left = st.top();
                st.pop();
            }
            if(!st.empty()) st.top() -> right = node;
            st.push(node);
        }

        while(st.size() != 1) st.pop();
        return st.top();
    }
};