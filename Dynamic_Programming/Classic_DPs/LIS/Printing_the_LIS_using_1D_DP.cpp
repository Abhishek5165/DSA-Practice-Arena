// Time complexity : O(N*N) + Length of the LIS;
// Space complexity : O(N) + O(N);

class Solution {
  public:
    vector<int> longestIncreasingSubsequence(int n, vector<int>& arr){
    
    vector<int>dp(n,1);
    vector<int>hash(n,1);
    
    int maxxi = INT_MIN;
    int lastIndex = 0;
    for(int i=0;i<n;i++){
    hash[i] = i;
    
    for(int prev = 0;prev<i;prev++){
    
    if(arr[prev] < arr[i] && 1 + dp[prev] > dp[i]){
    dp[i] = 1 + dp[prev];
    hash[i] = prev;
    }
    }
    if(dp[i] > maxxi){
    maxxi = dp[i];
    lastIndex = i;
    }
    }
   
    vector<int>temp;
    
    temp.push_back(arr[lastIndex]);
    
    while(hash[lastIndex] != lastIndex){
    lastIndex = hash[lastIndex];
    temp.push_back(arr[lastIndex]);
    }
    reverse(temp.begin(),temp.end());
    return temp;
    }
};
