// Recursion + Memoization....

// Time Complexity : O(n*2*3);
// Space Complexity : O(n*2*3) + O(n);

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
    int maxProfit(vector<int>& prices) { 
        int n = prices.size();
        vector<vector<vector<int>>>dp(n+1,
        vector<vector<int>>(2,vector<int>(3,-1)));

        return solve(0, 1, 2, prices,dp);
    }
};


// bottom up (tabulation)  .......

// Time Complexity : O(n*2*3);
// Space Complexity : O(n*2*3);


class Solution {
public:
    int maxProfit(vector<int>& prices) { 
        int n = prices.size();
        vector<vector<vector<int>>>dp(n+1,
        vector<vector<int>>(2,vector<int>(3,0)));

        for(int index=n-1;index>=0;index--){

        for(int buy = 0;buy<=1;buy++){

        for(int cap = 1;cap<=2;cap++){
        
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
        return dp[0][1][2];
    }
};

// ------------------------------------------------------------------

// Another approch - > using transactions (buy sell buy sell) == 4
// only possibilities for max 2 transactions this will give TLE ....

// This is recursion solution .........

class Solution {
public:
    int solve(int index,int transactions,vector<int>&prices){
    int n = prices.size();
    int profit = 0;
    if(index == n || transactions == 4){
        return 0;
    }
    if(transactions%2 == 0){
    profit = max(-prices[index] + solve(index+1,
    transactions+1,prices),0 + solve(index+1,transactions,prices));
    }
    else{
    profit = max(prices[index] + solve(index+1,
    transactions+1,prices),
    0 + solve(index+1,transactions,prices));
    }
    return profit;
    }
    int maxProfit(vector<int>& prices) {
    return solve(0,0,prices);
    }
};

// Another approch - > using transactions (buy sell buy sell) == 4
// only possibilities for max 2 transactions .............

// This is recursion + memoization solution .......


class Solution {
public: 
    int solve(int index,int transactions,
    vector<vector<int>>&dp,vector<int>&prices){

    int n = prices.size();
    int profit = 0;
    if(index == n || transactions == 4){
    return 0;
    }
    if(dp[index][transactions] != -1){
    return dp[index][transactions];
    }
    if(transactions%2 == 0){
    profit = max(-prices[index] + solve(index+1,transactions+1,dp,
    prices), 0 + solve(index+1,transactions,dp,prices));
    }
    else{
    profit = max(prices[index] + solve(index+1,transactions+1,dp,
    prices), 0 + solve(index+1,transactions,dp,prices));
    }
    return dp[index][transactions] = profit;
    }

    int maxProfit(vector<int>& prices) {
    int n = prices.size();
    vector<vector<int>>dp(n+1,vector<int>(4,-1));
    return solve(0,0,dp,prices);
    }
};


// bottom up (tabulation)  ....

// Time Complexity : O(n*4);
// Space Complexity : O(n*4);


class Solution {
  public: int maxProfit(vector < int > & prices) {
    int n = prices.size();
    vector < vector < int >> dp(n + 1, vector < int > (5, 0));

    for (int index = n - 1; index >= 0; index--) {
      for (int transactions = 0; transactions < 4; transactions++) {

        if (transactions % 2 == 0) {
          dp[index][transactions] =
            max(-prices[index] + dp[index + 1][transactions + 1],
              0 + dp[index + 1][transactions]);
        } 
        else {
          dp[index][transactions] =
            max(prices[index] + dp[index + 1][transactions + 1],
              0 + dp[index + 1][transactions]);
        }
      }
    }
    return dp[0][0];
  }
};

// Space optimizarion .......
// Time Complexity : O(n*4);
// Space Complexity : O(1);


class Solution {
  public: int maxProfit(vector < int > & prices) {
    int n = prices.size();
    vector<int>after(5,0);
    vector<int>curr(5,0);

    for (int index = n - 1; index >= 0; index--) {
      for (int transactions = 0; transactions < 4; transactions++) {

        if (transactions % 2 == 0) {
          curr[transactions] =
            max(-prices[index] + after[transactions + 1],
              0 + after[transactions]);
        } 
        else {
          curr[transactions] =
            max(prices[index] + after[transactions + 1],
              0 + after[transactions]);
        }
        after = curr;
      }
    }
    return after[0];
  }
};