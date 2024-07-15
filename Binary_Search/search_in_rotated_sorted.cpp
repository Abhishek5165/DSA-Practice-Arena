// Time complexity : o(logn);
// Space complexity : o(logn);

class Solution {
public:  
    int pivotIndex(vector<int>& nums){

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
    return left;
    }

    int binary(vector<int>& nums,int left,int right,int target){
    int ans = -1;
    while(left <= right){
    
    int mid = left + (right-left)/2;
    if(nums[mid] == target){
    ans = mid;
    break;
    }
    else if(nums[mid] < target){
    left = mid + 1;
    }
    else{
    right = mid - 1;
    }
    }
    return ans;
    }

    int search(vector<int>& nums, int target) {
    
    int n = nums.size();

    int index = pivotIndex(nums);
    int Abhishek = binary(nums,0,index-1,target);
    if(Abhishek != -1){
    return Abhishek;
    }
    Abhishek = binary(nums,index,n-1,target);
    return Abhishek;
    }
};