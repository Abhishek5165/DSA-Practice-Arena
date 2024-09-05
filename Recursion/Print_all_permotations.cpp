// Time Complexity : O(n ! * n);
// Space Complexity : O(n) recursion stack space.

class Solution {
public:
    void solve(int index,vector<int>& nums,vector<vector<int>>&ans){
    int n = nums.size();
   
    if(index == n){
    ans.push_back(nums);
    return;
    }
    for(int i=index;i<n;i++){
    swap(nums[i],nums[index]);
    solve(index+1,nums,ans);
    swap(nums[i],nums[index]);
    }
    }
    vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>>ans;
    solve(0,nums,ans);
    return ans;   
    }
};