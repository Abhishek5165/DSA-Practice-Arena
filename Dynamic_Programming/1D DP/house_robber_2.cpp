class Solution {
public:
    int dp[101];
    int solve(int i,int n, vector<int>&nums){
    if(i > n){
    return 0;
    }
    if(dp[i] != -1){
    return dp[i];
    }
    int take = nums[i] + solve(i+2,n,nums);
    int skip = 0 + solve(i+1,n,nums);
    return dp[i] = max(take,skip);
    }
    int rob(vector<int>& nums) {
    int n = nums.size();
    if(n == 1){
    return nums[0];
    }
    if(n == 2){
    return max(nums[0],nums[1]);
    }
    memset(dp,-1,sizeof(dp));

    int ans1 = solve(0,n-2,nums);
    memset(dp,-1,sizeof(dp));

    int ans2 = solve(1,n-1,nums);
    return max(ans1,ans2);
    }
};

// Space optimiation ...
// Time Complexity O(N);
// Space Complexity O(N);

class Solution {
public:
    int solve(vector<int>&nums){

    int prev = nums[0];
    int prev2 = 0;
    int sum = 0;
    int n = nums.size();

    for(int i=1;i<n;i++){
    int take = nums[i] + prev2;
    int skip = prev;
    
    sum = max(take,skip);
    prev2 = prev;
    prev = sum;
    }
    return prev;
    }
    int rob(vector<int>& nums) {
    int n = nums.size();

    if(n==1){
    return nums[0];
    }

    vector<int>temp1;
    vector<int>temp2;

    for(int i=0;i<n;i++){
    if(i != 0){
    temp1.push_back(nums[i]);
    }
    if(i != n-1){
    temp2.push_back(nums[i]);
    }
    }

    int ans1 = solve(temp1);
    int ans2 = solve(temp2);

    return max(ans1,ans2);
    }
};
