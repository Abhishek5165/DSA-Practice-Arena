// Top-Down .....
// Time Complexity O(N);
// Space Complexity O(N) + O(N);

// Approch - 1

class Solution {
  public:
    vector<int>dp;
    int solve(int index,vector<int>& height){
    
    int n = height.size();
    if(index >= n-1){
    return 0;
    }
    int one = INT_MAX;
    int two = INT_MAX;
    
    if(dp[index] != -1){
    return dp[index];
    }
    
    if(index+1 < n){
    one = abs(height[index] - height[index+1]) +
    solve(index+1,height);
    }
    if(index+2 < n){
    two = abs(height[index] - height[index+2]) +
    solve(index+2,height);
    }
    return dp[index] = min(one,two);
    }
    int minimumEnergy(vector<int>& height, int n) {
    dp.resize(n+1,-1);
    return solve(0,height);
    }
};


// Approch - 2

class Solution {
  public:
    vector<int>dp;
    int solve(int index,vector<int>&height){
    
    if(index == 0){
    return 0;
    }
    if(dp[index] != -1){
    return dp[index];
    }
    int two = INT_MAX;
    int one = solve(index-1,height) + 
    abs(height[index]-height[index-1]);
    if(index > 1){
    two = solve(index-2,height) + 
    abs(height[index]-height[index-2]);
    }
    return dp[index] = min(one,two);
    }
    int minimumEnergy(vector<int>& height, int n) {
    dp.resize(n+1,-1);
    return solve(n-1,height);
    }
};

// using bottom up...
// Time Complexity O(N);
// Space Complexity O(N);

class Solution {
  public:
    int minimumEnergy(vector<int>& height, int n) {
    vector<int>dp(n+1,-1);
    dp[0] = 0;
    int two = INT_MAX;
    int one = INT_MAX;
    
    for(int i=1;i<n;i++){
        
    one = dp[i-1] + abs(height[i]-height[i-1]);
    if(i>1){
    two = dp[i-2] + abs(height[i]-height[i-2]);
    }
    dp[i] = min(one,two);
    }
    return dp[n-1];
    }
};


// Space Optimization .......
// Time Complexity O(N);
// Space Complexity O(1);

class Solution {
  public:
    int minimumEnergy(vector<int>& height, int n) {
    
    int prev = 0;
    int prev2 = 0;
    
    int two = INT_MAX;
    int one = INT_MAX;
    int sum = INT_MAX;
    
    for(int i=1;i<n;i++){
        
    one = prev + abs(height[i]-height[i-1]);
    if(i>1){
    two = prev2 + abs(height[i]-height[i-2]);
    }
    sum = min(one,two);
    prev2 = prev;
    prev = sum;
    }
    return prev;
    }
};