// Recursion + Memoization solution ......

// Time Complexity : O(N*N) * O(N)  -> O(N^3);
// Space complexity : O(N*N) + O(N); This is for recursion stack space ....


class Solution {
public:
    int solve(int i,int j,vector<int>&cuts,vector<vector<int>>&dp){
    
    if(i > j){
    return 0;
    }
    if (dp[i][j] != -1) {
        return dp[i][j];
    }

    long long mini = 1e9;
    for(int index = i;index <= j;index++){
    long long ans = (long long)(cuts[j+1] - cuts[i-1]) + 
    solve(i,index-1,cuts,dp) + solve(index+1,j,cuts,dp);
    mini = min(mini,ans);
    }
    return dp[i][j] = mini;
    }
    int minCost(int n, vector<int>& cuts) {
    int c = cuts.size();
    cuts.push_back(n);
    cuts.insert(cuts.begin(),0);

    vector<vector<int>> dp(c+1,vector<int>(c+1, -1));
    sort(begin(cuts),end(cuts));
    return solve(1,c,cuts,dp);
    }
};

// Tabulation (bottom up) ......
// Time Complexity : O(N*N) * O(N)  -> O(N^3);
// Space complexity : O(N*N)


class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
    int c = cuts.size();
    cuts.push_back(n);
    cuts.insert(cuts.begin(),0);

    vector<vector<int>> dp(c+2,vector<int>(c+2, 0));
    sort(begin(cuts),end(cuts));

    for(int i=c;i>=1;i--){
    for(int j=1;j<=c;j++){
    long long mini = 1e9;
    if(i > j){
    continue;
    }
    for(int index = i;index <= j;index++){
    long long ans = (long long)(cuts[j+1] - cuts[i-1]) + 
    dp[i][index-1] + dp[index+1][j];
    mini = min(mini,ans);
    }
    dp[i][j] = mini;
    }
    }
    return dp[1][c];
    }
};