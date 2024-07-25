// Approch - 1 Brute Force  = TLE
// Time complexity : O(n*n);
// Space complexity : O(1);

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
    
    int n = nums.size();
    int maxxi = INT_MIN;

    for(int i=0;i<n;i++){
    int sum = 0;
    for(int j=i;j<n;j++){
    sum += nums[j];
    maxxi = max(maxxi,sum);
    }
    }
    return maxxi;
    }
};

// Approch - 2 Optimise 
// Time complexity : O(n);
// Space complexity : O(1);

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
    int maxxi = nums[0];
    int sum = 0;
    int n = nums.size();

    for(int i=0;i<n;i++){
    
    sum += nums[i];
    maxxi = max(maxxi,sum);

    if(sum < 0){
    sum = 0;
    }
    }
    return maxxi;
    }
};

// Optimised..

// Time complexity : O(n);
// Space complexity : O(1);

// follow up Question - print the subarray.

// if(sum == 0) start = i;
// int substart = start;
// int subend = i;

// between this the array is subarray with max sum..


