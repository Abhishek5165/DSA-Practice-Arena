// Time complexity : O(n);
// Space complexity : O(n);

class Solution {
public:
     
    bool findPath(TreeNode* root,int target, string &path){

    if(root == NULL){
    return false;
    }
    if(root->val == target){
    return true;
    }
    path.push_back('L');
    if(findPath(root->left,target,path) == true){
    return true;
    }
    path.pop_back();

    path.push_back('R');
    if(findPath(root->right,target,path) == true){
    return true;
    }
    path.pop_back();

    return false;
    }

    string getDirections(TreeNode* root, int 
    startValue, int destValue) {

    string rootTosrc = "";
    string rootTodes = "";

    findPath(root,startValue,rootTosrc);
    findPath(root,destValue,rootTodes);

    int k=0;

    while(k < rootTosrc.length() && k < rootTodes.length() &&
    rootTosrc[k] == rootTodes[k]){
    k++;
    }
    string result = "";

    for(int i=0;i<rootTosrc.size()-k;i++){
    result.push_back('U');
    }
    for(int i=k;i<rootTodes.size();i++){
    result.push_back(rootTodes[i]);
    }
    return result;
    }
};