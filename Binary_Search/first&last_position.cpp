// Time complexit : O(logn);
// Space complexit : O(1);

class Solution {
public:
    int solve1(vector<int>& nums,int n, int target){
    int left = 0;
    int right = n-1;

    int Leftindex = -1;
    while(left <= right){
    
    int mid = left + (right-left)/2;

    if(nums[mid] < target){
    left = mid + 1;
    }
    else if(nums[mid] > target){
    right = mid - 1;
    }
    else{
    Leftindex = mid;
    right = mid - 1;
    }
    }
    return Leftindex;
    }

    int solve2(vector<int>& nums,int n, int target){
    int left = 0;
    int right = n-1;

    int Rightindex = -1;
    while(left <= right){
    
    int mid = left + (right-left)/2;

    if(nums[mid] < target){
    left = mid + 1;
    }
    else if(nums[mid] > target){
    right = mid - 1;
    }
    else{
    Rightindex = mid;
    left = mid + 1;
    }
    }
    return Rightindex;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
    int n = nums.size();

    int Leftindex = solve1(nums,n,target);
    int Rightindex = solve2(nums,n,target);

    return {Leftindex,Rightindex};
    }
};