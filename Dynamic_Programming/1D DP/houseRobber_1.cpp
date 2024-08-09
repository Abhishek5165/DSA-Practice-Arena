// Giving TLE 
// recursion .....
// Time Complexity O(N);
// Space Complexity O(N);

class Solution {
public:
    int solve(int index,vector<int>&nums){
    int n = nums.size();
    if(index >= n){
    return 0;
    }
    int take = nums[index] + solve(index+2,nums);
    int skip = 0 + solve(index+1,nums);
    return max(take,skip);
    }
    int rob(vector<int>& nums) {
    int n = nums.size();
    if(n == 2){
    return max(nums[0],nums[1]);
    }
    return solve(0,nums);  
    }
};


// using bottom up...
// Time Complexity O(N);
// Space Complexity O(N);


class Solution {
public:
    vector<int>dp;
    int solve(int index,vector<int>&nums){
    int n = nums.size();
    if(index >= n){
    return 0;
    }
    if(dp[index] != -1){
    return dp[index];
    }
    int take = nums[index] + solve(index+2,nums);
    int skip = 0 + solve(index+1,nums);
    return dp[index] = max(take,skip);
    }
    int rob(vector<int>& nums) {
    int n = nums.size();
    dp.resize(n+1,-1);
    if(n == 2){
    return max(nums[0],nums[1]);
    }
    return solve(0,nums);     
    }
};


// using bottom up...
// Time Complexity O(N);
// Space Complexity O(N);

class Solution {
public:
    vector<int>dp;
    int rob(vector<int>& nums) {
    int n = nums.size();
    dp.resize(n+1,-1);
    dp[0] = 0;
    dp[1] = nums[0];

    for(int i=2;i<=n;i++){
    int take = nums[i-1] + dp[i-2];
    int skip = 0 + dp[i-1];
    dp[i] = max(take,skip);
    }
    return dp[n];
    }
};


// Space optimiation ...
// Time Complexity O(N);
// Space Complexity O(1);

class Solution {
public:
    int rob(vector<int>& nums) {
    int rob1 = 0,rob2 = 0;
    for(int & n : nums){
    int temp = max(n+rob1,rob2);
    rob1 = rob2;
    rob2 = temp;
    }   
    return rob2;
    }
};
