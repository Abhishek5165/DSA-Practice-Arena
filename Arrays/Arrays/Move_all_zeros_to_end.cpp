// Brute Force .... Using Extra Space..

// Time Complexity: O(N) + O(X) + O(N-X) ~ O(2*N)
// Space Complexity: O(N);


class Solution {
public:
    void moveZeroes(vector<int>& nums) {
    vector<int>temp;
    int n = nums.size();

    for(int i=0;i<n;i++){
    if(nums[i] != 0){
    temp.push_back(nums[i]);
    }
    }
    int sz = temp.size();
    for(int i=0;i<sz;i++){
    nums[i] = temp[i];
    }
    for(int i=sz;i<n;i++){
    nums[i] = 0;
    }
    }
};


// Time Complexity: O(N), N = size of the array.
// Space Complexity: O(1), N = size of the array.

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
    int j=-1;
    int n = nums.size();
    for(int i=0;i<n;i++){
    if(nums[i] == 0){
    j = i;
    break;
    }
    }    
    if(j == -1){
    return;
    }
    for(int i=j+1;i<n;i++){
    if(nums[i] != 0){
    swap(nums[i],nums[j]);
    j++;
    }
    }
    }
};