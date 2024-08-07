// Giving TLE for larger test cases ....
// Using top Down ....
// Time Complexity O(2^N);
// Space Complexity O(N);

class Solution {
public:
    int solve(int index,vector<int>& cost){
    int n = cost.size();
    if(index >= n){
    return 0;
    }
    int one = cost[index] + solve(index+1,cost);
    int two = cost[index] + solve(index+2,cost);
    return min(one,two);
    }
    int minCostClimbingStairs(vector<int>& cost) {
    int i=0;
    return min(solve(i,cost),solve(i+1,cost));
    }
};


// using bottom up...
// Time Complexity O(N);
// Space Complexity O(N);

class Solution {
public:
    int dp[101];
    int solve(int index,vector<int>& cost){
    int n = cost.size();
    if(index >= n){
    return 0;
    }
    if(dp[index] != -1){
    return dp[index];
    }
    int one = cost[index] + solve(index+1,cost);
    int two = cost[index] + solve(index+2,cost);
    return dp[index] = min(one,two);
    }
    int minCostClimbingStairs(vector<int>& cost) {
    memset(dp,-1,sizeof(dp));
    int i=0;
    return min(solve(i,cost),solve(i+1,cost));
    }
};


// Time Complexity : O(n);
// Space Complexity : O(1);


class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
    
    int n = cost.size();
    if(n <= 2){
    return min(cost[0],cost[1]);
    }
    for(int i=2;i<n;i++){
    cost[i] = cost[i] + min(cost[i-1],cost[i-2]);
    }   
    return min(cost[n-1],cost[n-2]);
    }
};