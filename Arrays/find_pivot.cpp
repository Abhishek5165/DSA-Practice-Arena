// Brute Force ...............

// Time complexity : O(n^2);
// Space complexity : O(1);

class Solution {
public:
    int solve(vector<int>& nums, int left, int right) {
        int sum = 0;

        for (int i = left; i <= right; i++) {
            sum += nums[i];
        }
        return sum;
    }
    int pivotIndex(vector<int>& nums) {

        int n = nums.size();
        if (n == 1) {
            return 0;
        }
        int index = -1;

        int findLeftSum = 0;
        int findRightSum = 0;

        for (int i = 0; i < n; i++) {

            findLeftSum = solve(nums, 0, i - 1);
            findRightSum = solve(nums, i + 1, n - 1);

            if (findLeftSum == findRightSum) {
                index = i;
                break;
            }
        }
        return index;
    }
};

// Time complexity : O(n);
// Space complexity : O(1);


class Solution {
public:
    int pivotIndex(vector<int>& nums) {

    int sum = 0;
    int n = nums.size();
    
    for(auto &it : nums){
    sum += it;
    }  
    int LS = 0;
    for(int i=0;i<n;i++){
    int RS = sum - LS - nums[i];
    if(LS == RS){
      return i;
      break;
    }
    LS += nums[i];
    }
    return -1;
    }
};


// Note -> same questions.

// 1. Find the Pivot integer;
// 2. Find the Equilibrium Point;
// 3. FInd the middle index of the Array;
// 4. Left and Right Sum Differences.