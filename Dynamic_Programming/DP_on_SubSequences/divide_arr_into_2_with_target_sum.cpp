
// Bottom up ......

// This is a extension of the proble subset sum = target

// Time Complexity : O(N*target);
// Space Complexity : O(N*target);


class Solution {
public:
    bool canPartition(vector<int>& nums) {
    int target = 0;
    int n = nums.size();
    int sum = 0;
    for(int i=0;i<n;i++){
     sum += nums[i];
    }
    if(sum&1){
    return false;
    }
    else{
    target = sum/2;
    }
    vector<vector<bool>>dp(n+1,vector<bool>(target+1,false)); 
    for(int i=0;i<n;i++){
        dp[i][0] = true;
    }   

    for(int i=1;i<n;i++){
        for(int j=1;j<=target;j++){
            bool notTake = dp[i-1][j];
            bool take = false;
            if(j >= nums[i]){
               take = dp[i-1][j-nums[i]];
            }
        dp[i][j] = take || notTake;
        }
    }
    return dp[n-1][target];
    }
};