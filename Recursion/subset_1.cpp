
// Backtracking (Recursive Approach)🤓:  TC - O(n^2 * n)

class Solution {
public:
    
    void solve(vector<vector<int>>&ans,
    vector<int>&temp,vector<int>&nums,int index){

    ans.push_back(temp);
    for(int i=index;i<nums.size();i++){

    temp.push_back(nums[i]);
    solve(ans,temp,nums,i+1);
    temp.pop_back();
    }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        
    vector<vector<int>>ans;
    vector<int>temp;
    solve(ans,temp,nums,0);
    return ans;
    }
};

️
// Bit Manipulation😎:  


class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        
    vector<vector<int>>ans;
    int n = nums.size();

    for(int i=0;i<(1<<n);i++){
    
    vector<int>subset;

    for(int j=0;j<n;j++){

    if((i&(1<<j)) > 0){

    subset.push_back(nums[j]);
    }
    }
    ans.push_back(subset);
    }
    return ans;
    }
};


// Iterative Approach (Generating All Subsets)😎:

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result = {{}};
        for (int num : nums) {
            int size = result.size();
            for (int i = 0; i < size; i++) {
                vector<int> subset = result[i];
                subset.push_back(num);
                result.push_back(subset);
            }
        }
        return result;
    }
};