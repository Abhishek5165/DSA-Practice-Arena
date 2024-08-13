// Time complexity : O(N*N);
// Space complexity : O(N);

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
    int n = nums.size();

    vector<int>dp(n+1,1);
    vector<int>ct(n+1,1);

    int maxxi = INT_MIN;
    for(int i=0;i<n;i++){
    for(int prev = 0;prev<i;prev++){
    
    if(nums[prev] < nums[i] && 1+dp[prev] > dp[i]){
    dp[i] = 1 + dp[prev];
    ct[i] = ct[prev];
    }
    else if(nums[prev] < nums[i] && 1+dp[prev] == dp[i]){
    ct[i] = ct[i] + ct[prev];
    }
    }
    maxxi = max(maxxi,dp[i]);
    }
    int count = 0;
    for(int i=0;i<n;i++){
    if(dp[i] == maxxi){
    count += ct[i];
    }
    }
    return count; 
    }
};