// Time Complexity : O(N*N);
// Space Complexity : O(N*N) + O(N);

// Approch - 1 Recurrsion + Memoization.
 
class Solution {
public:
    int dp[2501][2501];

    int solve(vector<int>& nums, int i, int prev) {

        int n = nums.size();

        if (i >= n) {
            return 0;
        }
        if (prev != -1 && dp[i][prev] != -1) {
            return dp[i][prev];
        }
        int take = 0;
        if (prev == -1 || nums[prev] < nums[i]) {
            take = 1 + solve(nums, i + 1, i);
        }
        int skip = solve(nums, i + 1, prev);
        if (prev != -1) {
            dp[i][prev] = max(take, skip);
        }
        return max(take, skip);
    }

    int lengthOfLIS(vector<int>& nums) {

        int index = 0;
        int prev = -1;

        memset(dp, -1, sizeof(dp));

        int ans = solve(nums, index, prev);
        return ans;
    }
};


// tabulation Approch - 1 
// Time complexity : O(N*N);
// Space complexity : O(N*N);


class Solution {
public:

    int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>>dp(n+1,vector<int>(n+1,0));

    for(int index = n-1;index>=0;index--){
    for(int prev = index-1;prev>=-1;prev--){

    int len = dp[index+1][prev+1];
    
    if(prev == -1 || nums[index] > nums[prev]){
    len = max(len,1 + dp[index+1][index+1]);
    }
    dp[index][prev+1] = len;
    }
    }
    return dp[0][-1+1];
    }
};


// Space Optimization ....

// Time complexity : O(N*N);
// Space complexity : O(N);

class Solution {
public:

    int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    vector<int>next(n+1,0);
    vector<int>curr(n+1,0);

    for(int index = n-1;index>=0;index--){
    for(int prev = index-1;prev>=-1;prev--){

    int len = next[prev+1];
    
    if(prev == -1 || nums[index] > nums[prev]){
    len = max(len,1 + next[index+1]);
    }
    curr[prev+1] = len;
    }
    next = curr;
    }
    return next[-1+1];
    }
};


// Approch - 2 For finding the LIS .....

// This Solution required when we have to print the LIS ....

// Time complexity : O(N*N);
// Space complexity : O(N);


class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    vector<int>dp(n+1,1);
    int maxxi = INT_MIN;
    for(int i=0;i<n;i++){
    for(int prev = 0;prev<i;prev++){
    
    if(nums[prev] < nums[i]){
    dp[i] = max(dp[i],1+dp[prev]);
    }
    }
    maxxi = max(maxxi,dp[i]);
    }
    return maxxi;
    }
};