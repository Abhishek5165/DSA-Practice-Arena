// Time complexity : o(logn);
// Space complexity : o(logn);

class Solution {
public:
    int findMin(vector<int>& nums) {
    int n = nums.size();
    int left = 0;
    int right = n-1;

    while(left < right){
    
    int mid = left + (right-left)/2;

    if(nums[mid] > nums[right]){
    left = mid+1;
    }
    else{
    right = mid;
    }
    }
    return nums[left];
    }
};


// Follow Up Question - 

// 1. How many times array was rotated.
// Ans = simply return the index of (left or right);

// 2. Search in Rotated Sorted array (i),(ii).