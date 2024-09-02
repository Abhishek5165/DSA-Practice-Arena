// Brute Force ....

// Time complexity: O(n*log(n))+O(n)
// Space Complexity: O(n) 

int removeDuplicates(int arr[], int n) {
  set < int > set;
  for (int i = 0; i < n; i++) {
    set.insert(arr[i]);
  }
  int k = set.size();
  int j = 0;
  for (int x: set) {
    arr[j++] = x;
  }
  return k;
}

// Time complexity: O(n)
// Space Complexity: O(1) 

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
    int n = nums.size();
    int k = 0;
    for(int i=1;i<n;i++){
    if(nums[k] != nums[i]){
    k++;
    nums[k] = nums[i];
    }
    } 
    return (k+1);
    }
};