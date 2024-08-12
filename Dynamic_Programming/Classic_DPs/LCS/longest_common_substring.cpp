
// Bottom Up (tabulation) .......
// Time Complexity : O(N*M); 
// Space Complexity : O(N*M);

class Solution {
  public:
    int longestCommonSubstr(string s1, string s2) {
    int n = s1.size();
    int m = s2.size();
    vector<vector<int>>dp((n+1),vector<int>(m+1));
    int ans = 0;
    for(int i=0;i<n+1;i++){
    dp[i][0] = 0;
    }
    for(int j=0;j<m+1;j++){
    dp[0][j] = 0;
    }
    for(int i=1;i<n+1;i++){
    for(int j=1;j<m+1;j++){
    
    if(s1[i-1] == s2[j-1]){
    dp[i][j] = 1 + dp[i-1][j-1];
    ans = max(ans,dp[i][j]);
    }
    }
    }
    return ans;
    }
};