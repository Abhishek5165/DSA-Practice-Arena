// This is a recursion solution very expensive solution giving TLE ....
// Time complexity : exponential ...

class Solution{
public:
    
    int solve(int i,int j,int arr[]){
    
    if(i==j){
    return 0;
    }
    int mini = INT_MAX;
    int steps = 0;
    
    for(int k=i;k <=j-1;k++){
    
    steps = arr[i-1]*arr[k]*arr[j];
    int ans = steps + solve(i,k,arr) + solve(k+1,j,arr);
    mini = min(mini,ans);
    }
    return mini;
    }
    
    int matrixMultiplication(int N, int arr[])
    {
    return solve(1,N-1,arr);
    }
};


// Now Come to the Recursion + Memoization solution ......

// Time Complexity : O(N*N) * O(N)  -> O(N^3);
// O(N*N) for i & j states total and another O(N) is for k loop
// Space complexity : O(N*N) + O(N); This is for recursion stack space ....


class Solution{
public:
    
    int solve(int i,int j,int arr[],vector<vector<int>>&dp){
    
    if(i==j){
    return 0;
    }
    int mini = INT_MAX;
    int steps = 0;
    
    if(dp[i][j] != -1){
    return dp[i][j];
    }
    
    for(int k=i;k <=j-1;k++){
    
    steps = arr[i-1]*arr[k]*arr[j];
    int ans = steps + solve(i,k,arr,dp) + solve(k+1,j,arr,dp);
    mini = min(mini,ans);
    }
    return dp[i][j] = mini;
    }
    
    int matrixMultiplication(int N, int arr[])
    {
    vector<vector<int>>dp(N+1,vector<int>(N+1,-1));
    return solve(1,N-1,arr,dp);
    }
};


// Now Come to the Tabulation (bottom up) solution ......

// Time Complexity : O(N*N) * O(N)  -> O(N^3);
// O(N*N) for i & j states total and another O(N) is for k loop
// Space complexity : O(N*N)

class Solution{
public:
    int matrixMultiplication(int N, int arr[])
    {
    vector<vector<int>>dp(N+1,vector<int>(N+1));
    for(int i=0;i<N;i++){
    dp[i][i] = 0;
    }
    
    int steps = 0;
    for(int i=N-1;i>=1;i--){
    for(int j=i+1;j<N;j++){
        
    int mini = 1e9;
    for(int k=i;k <=j-1;k++){
    
    steps = arr[i-1]*arr[k]*arr[j];
    int ans = steps + dp[i][k] + dp[k+1][j];
    mini = min(mini,ans);
    }
    dp[i][j] = mini;
    }
    }
    return dp[1][N-1];
    }
};
