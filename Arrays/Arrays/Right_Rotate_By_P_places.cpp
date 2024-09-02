// Time Complexity : O(k) + O(n-k) + O(k);  ~= O(n-k)
// Space Complexity : O(k);

class Solution {
public:
    void rotateRight(vector<int>& nums, int k) {

        int n = nums.size();
        k = k % n;
        
        // Step - 1: Store the last k elements in temp
        vector<int> temp(k);
        for (int i = 0; i < k; i++) {
            temp[i] = nums[n - k + i];
        }
        
        // Step - 2: Shift the rest of the array to the right
        for (int i = n - 1; i >= k; i--) {
            nums[i] = nums[i - k];
        }
        
        // Step - 3: Reassign the stored elements to the front
        for (int i = 0; i < k; i++) {
            nums[i] = temp[i];
        }
    }
};


// Time Complexity : O(k) + O(n - k) + O(n), which simplifies to O(n).
// Space Complexity : O(1);


class Solution {
void reverse(vector<int>&nums,int start,int end){
while(start < end){
nums[start] = nums[start] + nums[end];
nums[end] = nums[start] - nums[end];
nums[start] = nums[start] - nums[end];
start++;
end--;
}
}
public:
    void rotate(vector<int>& nums, int k) {
    int n = nums.size();
    k = k % n;
    reverse(nums,0,n-1);
    reverse(nums,0,k-1);
    reverse(nums,k,n-1);
    }
};