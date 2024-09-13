// Same as Longest subarray with sum k both Positive and negative...

// time Complexity : O(N*logN);
// Space Complexity : O(N);

#include<vector>
#include<bits/stdc++.h>
int getLongestZeroSumSubarrayLength(vector<int> &arr){

int ans = 0;
int sum = 0;
int n = arr.size();

unordered_map<int,int>mpp;

for(int i=0;i<n;i++){
sum += arr[i];

if(sum == 0){
ans = i+1;
}
if(mpp.find(sum) != mpp.end()){
int len = i - mpp[sum];
ans = max(ans,len);
}
if(mpp.find(sum) == mpp.end()){
mpp[sum] = i;
}
}
return ans;
}