// Time Complexity : O(N*N);
// Space Complexity : O(1);

// Better Approch ....

class Solution {
public:
    int maxProduct(vector<int>& nums) {
    int maxxi = nums[0];
    int n = nums.size();
    for(int i=0;i<n;i++){
    int pro = 1;
    for(int j=i;j<n;j++){
    pro = nums[j] * pro;
    if(pro >= maxxi){
    maxxi = pro;
    }
    }
    }
    return maxxi;
    }
};

// Optimal Approch - 1;

// Time Compleixty : O(N);
// Space Complexity : O(1);

class Solution {
public:
    int maxProduct(vector<int>& nums) {
    int n = nums.size();
    int prefix = 1,suffix = 1;
    int result = INT_MIN;

    for(int i=0;i<n;i++){
    if(prefix == 0){
    prefix = 1;
    }
    if(suffix == 0){
    suffix = 1;
    }
    prefix *= nums[i];
    suffix *= nums[n-1-i];
    result = max(result,max(prefix,suffix));
    } 
    return result;
    }
};


// Optimal Approch - 1 = Inspired with Kadane's Algorithm.....

// Time Compleixty : O(N);
// Space Complexity : O(1);


#include<vector>

int subarrayWithMaxProduct(vector<int> &arr){	
int n = arr.size();
int maxxi = arr[0];
int prod1 = arr[0];
int prod2 = arr[0];

for (int i = 1; i < n; i++) {
  int temp = max({arr[i], prod1 * arr[i], prod2 * arr[i]});
prod2 = min({arr[i],prod1*arr[i],prod2*arr[i]});
prod1 = temp;

maxxi = max(maxxi,temp);
}
return maxxi;
}
