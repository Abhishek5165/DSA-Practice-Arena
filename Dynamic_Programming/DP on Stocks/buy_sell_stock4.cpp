// Recursion + Memoization....

// Time Complexity : O(n*2*k);
// Space Complexity : O(n*2*k) + O(n);

class Solution {
public:
    int solve(int index, int buy, int cap, vector<int>& prices,
    vector<vector<vector<int>>>&dp) {
        int n = prices.size();
        int profit = 0;
        if (index == n || cap == 0) {
            return 0;
        }
        if(dp[index][buy][cap] != -1){
        return dp[index][buy][cap];
        }
        if (buy) {
            profit = max(-prices[index] + 
            solve(index + 1, 0, cap, prices,dp),
            0 + solve(index + 1, 1, cap, prices,dp));
        } 
        else {
            profit = max(prices[index] + 
            solve(index + 1, 1, cap - 1, prices,dp),
            0 + solve(index + 1, 0, cap, prices,dp));
        }
        return dp[index][buy][cap] = profit;
    }
    int maxProfit(int k,vector<int>& prices) { 
        int n = prices.size();
        vector<vector<vector<int>>>dp(n+1,
        vector<vector<int>>(2,vector<int>(k+1,-1)));

        return solve(0, 1, k, prices,dp);
    }
};


// bottom up (tabulation)....

// Time Complexity : O(n*2*k);
// Space Complexity : O(n*2*k);

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) { 
        int n = prices.size();
        vector<vector<vector<int>>>dp(n+1,
        vector<vector<int>>(2,vector<int>(k+1,0)));

        for(int index=n-1;index>=0;index--){

        for(int buy = 0;buy<=1;buy++){

        for(int cap = 1;cap<=k;cap++){
        
        if (buy) {
            dp[index][buy][cap] = max(-prices[index] + 
            dp[index+1][0][cap], 0 + dp[index+1][1][cap]);
        } 
        else {
            dp[index][buy][cap] = max(prices[index] + 
            dp[index+1][1][cap-1], 0 + dp[index+1][0][cap]);
        }
        }
        }
        }
        return dp[0][1][k];
    }
};

// -----------------------------------------------------------------

// Another approch - > using transactions
//  (buy sell buy sell) == 2*k why 2*k 
// because 1 transection contains 2 parts( buy and sell) this will give TLE ....

// This is recursion solution .........


class Solution {
public: 
    int solve(int index,int transactions,int k, vector<int>&prices){
    int n = prices.size();
    int profit = 0;
    if(index == n || transactions == 2*k){
    return 0;
    }
    if(transactions%2 == 0){
    profit = max(-prices[index] + solve(index+1,transactions+1,k,
    prices), 0 + solve(index+1,transactions,k,prices));
    }
    else{
    profit = max(prices[index] + solve(index+1,transactions+1,k,
    prices), 0 + solve(index+1,transactions,k,prices));
    }
    return profit;
    }

    int maxProfit(int k, vector<int>& prices) {
    return solve(0,0,k,prices);
    }
};


// Another approch - > using transactions
// (buy sell buy sell) == 2*k why 2*k 
// because 1 transection contains 2 parts( buy and sell) ....

// This is recursion + memoization solution .......

// Time Complexity : O(n*k);
// Space Complexity : O(n*k) + O(n);

class Solution {
public: 
    int solve(int index,int transections,int k, vector<int>&prices,
    vector<vector<int>>&dp){
    int n = prices.size();
    int profit = 0;
    if(index == n || transections == 2*k){
    return 0;
    }
    if(dp[index][transections] != -1){
    return dp[index][transections];
    }
    if(transections%2 == 0){
    profit = max(-prices[index] + solve(index+1,transections+1,k,
    prices,dp), 0 + solve(index+1,transections,k,prices,dp));
    }
    else{
    profit = max(prices[index] + solve(index+1,transections+1,k,
    prices,dp), 0 + solve(index+1,transections,k,prices,dp));
    }
    return dp[index][transections] = profit;
    }

    int maxProfit(int k, vector<int>& prices) {
    int n = prices.size();

    vector<vector<int>>dp(n+1,vector<int>(2*k,-1));
    return solve(0,0,k,prices,dp);
    }
};



// bottom up (tabulation) ....

// Time Complexity : O(n*k);
// Space Complexity : O(n*k);

class Solution {
public: 

    int maxProfit(int k, vector<int>& prices) {
    int n = prices.size();
    vector<vector<int>>dp(n+1,vector<int>(2*k+1,0));

    for(int index = n-1;index>=0;index--){
    for(int transactions = 0;transactions <= 2*k-1;transactions++){

    if(transactions%2 == 0){
    dp[index][transactions] = max(-prices[index] + 
    dp[index+1][transactions+1], 0 + dp[index+1][transactions]);
    }
    else{
    dp[index][transactions] = max(prices[index] + 
    dp[index+1][transactions+1], 0 + dp[index+1][transactions]);
    }
    }
    }
    return dp[0][0];
    }
};


// Space optimizarion .......
// Time Complexity : O(n*k);
// Space Complexity : O(1);


class Solution {
public: 

    int maxProfit(int k, vector<int>& prices) {
    int n = prices.size();
    vector<int>after(2*k+1,0);
    vector<int>curr(2*k+1,0);

    for(int index = n-1;index>=0;index--){
    for(int transactions = 0;transactions <= 2*k-1;transactions++){

    if(transactions%2 == 0){
    curr[transactions] = max(-prices[index] + 
    after[transactions+1], 0 + after[transactions]);
    }
    else{
    curr[transactions] = max(prices[index] + 
    after[transactions+1], 0 + after[transactions]);
    }
    after = curr;
    }
    }
    return after[0];
    }
};