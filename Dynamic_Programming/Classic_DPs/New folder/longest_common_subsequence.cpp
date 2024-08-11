// Time Complexity : O(2^n) * O(2^m);
// Space Complexity : O(2^n + 2^m); + O(n*m);

class Solution {
public:
    int solve(int i,int j,string &text1,string &text2){
    
    if(i < 0 || j < 0){
    return 0;
    }
    if(text1[i] == text2[j]){
    return 1 + solve(i-1,j-1,text1,text2);
    }
    return 0 + max(solve(i,j-1,text1,text2),
    solve(i-1,j,text1,text2));
    }

    int longestCommonSubsequence(string text1, string text2) {
    int n1 = text1.size();
    int n2 = text2.size();
    int i = n1-1;
    int j = n2-1;
    return solve(i,j,text1,text2); 
    }
};

// Recusion + Memoization solution .....

// Time Complexity : O(N*M); 
// Space Complexity : O(N+M) + O(N+M);


class Solution {
public:
    int solve(int i,int j,string &text1,string 
    &text2,vector<vector<int>>&dp){
    
    if(i < 0 || j < 0){
    return 0;
    }
    if(dp[i][j] != -1){
    return dp[i][j];
    }
    if(text1[i] == text2[j]){
    return dp[i][j] = 1 + solve(i-1,j-1,text1,text2,dp);
    }
    return dp[i][j] = 0 + max(solve(i,j-1,text1,text2,dp),
    solve(i-1,j,text1,text2,dp));
    }

    int longestCommonSubsequence(string text1, string text2) {
    int n1 = text1.size();
    int n2 = text2.size();
    vector<vector<int>>dp(n1+1,vector<int>(n2+1,-1));
    int i = n1-1;
    int j = n2-1;
    return solve(i,j,text1,text2,dp); 
    }
};


// Bottom Up (tabulation) .......
// Time Complexity : O(N*M); 
// Space Complexity : O(N+M);
class Solution {
public:

    int longestCommonSubsequence(string text1, string text2) {
    int n = text1.size();
    int m = text2.size();
    vector<vector<int>>dp(n+1,vector<int>(m+1));
    
    for(int i=0;i<n+1;i++){
    dp[i][0] = 0;
    }
    for(int j=0;j<m+1;j++){
    dp[0][j] = 0;
    }
    for(int i=1;i<n+1;i++){
    for(int j=1;j<m+1;j++){
    if(text1[i-1] == text2[j-1]){
    dp[i][j] = 1 + dp[i-1][j-1];
    }
    else{
    dp[i][j] = 0 + max(dp[i-1][j],dp[i][j-1]);
    }
    }
    }
    return dp[n][m];
    }
};


// Space opyimization ......
// Time Complexity : O(N*M); 
// Space Complexity : O(N);

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
    int n = text1.size();
    int m = text2.size();
    vector<int>prev(m+1,0);
    vector<int>curr(m+1,0);

    for(int i=1;i<n+1;i++){
    for(int j=1;j<m+1;j++){
    if(text1[i-1] == text2[j-1]){
    curr[j] = 1 + prev[j-1];
    }
    else{
    curr[j] = 0 + max(prev[j],curr[j-1]);
    }
    }
    prev = curr;
    }
    return prev[m];
    }
};