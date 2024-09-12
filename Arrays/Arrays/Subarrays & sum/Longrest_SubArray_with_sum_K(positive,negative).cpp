// Time Complexity : O(N*N);
// Space Complexity : O(1);

// Only positive Allowed ....

#include <bits/stdc++.h>
int getLongestSubarray(vector<int> &nums, int k) {

  int maxxi = 0;
  int N = nums.size();

  for (int i = 0; i < N; i++) {
    int sum = 0;
    for (int j = i; j < N; j++) {
      sum += nums[j];

      if (sum == k) {
        maxxi = max(maxxi, j - i + 1);
      }
    }
  }
  return maxxi;
}

// Time Complexity: O(N) or O(N*logN) depending on which map data structure we are using, where N = size of the array.
// Space Complexity: O(N) as we are using a map data structure.

#include <bits/stdc++.h>
int getLongestSubarray(vector<int> &nums, int k) {
int n = nums.size();
map<int,int>mpp;
int sum = 0;
int maxxi = 0;

for(int i=0;i<n;i++){

sum += nums[i];

if(sum == k){
maxxi = max(maxxi,i+1);
}
int rem = sum-k;
if(mpp.find(rem) != mpp.end()){
int len = i-mpp[rem];
maxxi = max(maxxi,len);
}
if(mpp.find(sum) == mpp.end()) {
mpp[sum] = i;
}
}
return maxxi;
}

// Only positive then use the Optimal (two pointer);
// Other wise The map based solution is most optimal ..

// Time Complexity: O(2*N), where N = size of the given array.
// Space Complexity: O(1) 

#include <bits/stdc++.h> 
using namespace std;
int getLongestSubarray(vector<int>& nums, int k) {
   
    int left = 0;
    int right = 0;
    int n = nums.size();
    int sum = nums[0];
    int maxxi = 0;

    while (right < n) {
        while (left <= right && sum > k) {
            sum -= nums[left];
            left++;
        }
        if (sum == k) {
            maxxi = max(maxxi, right - left + 1);
        }
        right++;
        if (right < n) {
            sum += nums[right];
        }
    }
    return maxxi;
}

