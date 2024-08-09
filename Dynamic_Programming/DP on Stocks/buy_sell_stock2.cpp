// Recursion + Memoization....

// Time Complexity : O(n*2);
// Space Complexity : O(n*2) + O(n);

class Solution {
public: 
    int dp[100001][2];
    int solve(int index, vector<int>& prices, int buy) {
        int n = prices.size();
        int profit = 0;
        if (index == n) {
            return 0;
        }
        if(dp[index][buy] != -1){
        return dp[index][buy];
        }
        if (buy) {
        profit = max(-prices[index] + 
        solve(index + 1, prices, 0), 
        0 + solve(index + 1, prices, 1));
        } 
        else {
        profit = max(prices[index] + 
        solve(index + 1, prices, 1),
        0 + solve(index + 1, prices, 0));
        }
        return dp[index][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int n = prices.size();
        memset(dp,-1,sizeof(dp));
        profit = solve(0, prices, 1);
        return profit;
    }
};


// bottom up (tabulation) ....

// Time Complexity : O(n*2);
// Space Complexity : O(n*2);


class Solution {
public: 
    int maxProfit(vector<int>& prices) {

        int n = prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2,0));
        dp[n][0] = 0;
        dp[n][1] = 0;

        int profit = 0;

        for(int index = n-1;index>=0;index--){
        for(int buy = 0;buy <= 1;buy++){
        

        if (buy) {
        profit = max(-prices[index] + 
        dp[index+1][0], 0 + dp[index+1][1]);
        } 
        else {
        profit = max(prices[index] + 
        dp[index+1][1], 0 + dp[index+1][0]);
        }
        dp[index][buy] = profit;
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
        vector<int>ahead(2,0);
        vector<int>curr(2,0);

        ahead[0] = ahead[1] = 0;

        int profit = 0;

        for(int index = n-1;index>=0;index--){
        for(int buy = 0;buy <= 1;buy++){

        if (buy) {
        profit = max(-prices[index] + 
        ahead[0], 0 + ahead[1]);
        } 
        else {
        profit = max(prices[index] + 
        ahead[1], 0 + ahead[0]);
        }
        curr[buy] = profit;
        }
        ahead = curr;
        }
        return ahead[1];
        }
};


// Space optimizarion using 4 variables .......
// Time Complexity : O(n);
// Space Complexity : O(1);


class Solution {
public: 
    int maxProfit(vector<int>& prices) {

        int n = prices.size();

        int aheadNotBuy,aheadBuy;
        int currNotBuy,currBuy;

        aheadNotBuy = 0;
        aheadBuy = 0;

        for(int index = n-1;index>=0;index--){
            
        currBuy = max(-prices[index] + 
        aheadNotBuy, 0 + aheadBuy);

        currNotBuy = max(prices[index] + 
        aheadBuy, 0 + aheadNotBuy);


        aheadBuy = currBuy;
        aheadNotBuy = currNotBuy;
        }
        return aheadBuy;
        }
};