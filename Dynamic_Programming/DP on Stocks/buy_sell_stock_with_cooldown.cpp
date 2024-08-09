// Recursion giving TLE.....

class Solution {
public:
    int solve(int index,int buy,vector<int>&prices){
    int n = prices.size();
    int profit = 0;
    if(index >= n){
    return 0;
    }
    if(buy){
    profit = max(-prices[index] + solve(index+1,0,prices), 
    0 + solve(index+1,1,prices));
    }
    else{
    profit = max(prices[index] + solve(index+2,1,prices), 
    0 + solve(index+1,0,prices));
    }
    return profit;
    }
    int maxProfit(vector<int>& prices) {
    return solve(0,1,prices);    
    }
};

// Recursion + Memoization....

// Time Complexity : O(n*2);
// Space Complexity : O(n*2) + O(n);


class Solution {
public:
    int dp[50001][2];
    int solve(int index,int buy,vector<int>&prices){
    int n = prices.size();
    int profit = 0;
    if(index >= n){
    return 0;
    }
    if(dp[index][buy] != -1){
    return dp[index][buy];
    }
    if(buy){
    profit = max(-prices[index] + solve(index+1,0,prices), 
    0 + solve(index+1,1,prices));
    }
    else{
    profit = max(prices[index] + solve(index+2,1,prices), 
    0 + solve(index+1,0,prices));
    }
    return dp[index][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {
    int n = prices.size();
    memset(dp,-1,sizeof(dp));
    return solve(0,1,prices);    
    }
};

// bottom up (tabulation) ....

// Time Complexity : O(n*2);
// Space Complexity : O(n*2);

class Solution {
public:
    int maxProfit(vector<int>& prices) {
    int n = prices.size();
    vector<vector<int>>dp(n+2,vector<int>(2,0));

    for(int index=n-1;index >= 0;index--){
    for(int buy=0;buy<=1;buy++){
    
    if(buy){
    dp[index][buy] = max(-prices[index] + 
    dp[index+1][0], 0 +  dp[index+1][1]);
    }
    else{
    dp[index][buy] = max(prices[index] + dp[index+2][1], 
    0 + dp[index+1][0]);
    }
    }
    }
    return dp[0][1];    
    }
};

// Space optimizarion using two arrays .......
// Time Complexity : O(n*2);
// Space Complexity : O(constant);

class Solution {
public:
    int maxProfit(vector<int>& prices) {
    int n = prices.size();
    vector<int>front1(2,0);
    vector<int>front2(2,0);
    vector<int>curr(2,0);

    for(int index=n-1;index >= 0;index--){
    for(int buy=0;buy<=1;buy++){
    
    if(buy){
    curr[buy] = max(-prices[index] + 
    front1[0], 0 +  front1[1]);
    }
    else{
    curr[buy] = max(prices[index] + front2[1], 
    0 + front1[0]);
    }
    front2 = front1;
    front1 = curr;
    }
    }
    return front1[1];    
    }
};