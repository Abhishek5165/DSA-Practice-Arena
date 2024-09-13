// Time Complexity : O(N*N);
// Space Complexity : O(1);

// Brute Force ....

class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        for (int i = 0; i < n; i++) {
            int num = nums[i];
            for (int j = i + 1; j < n; j++) {
                long long ans = 2 * nums[j];
                if (num > ans) {
                    count++;
                }
            }
        }
        return count;
    }
};


// Optimal Approch : 

// Time Complexity: O(2N*logN);
// Space Complexity : O(N);

class Solution {
public:
    void merge(vector<int>& nums, int low, int mid, int high) {
        vector<int> temp;
        int left = low;
        int right = mid + 1;

        while (left <= mid && right <= high) {

            if (nums[left] < nums[right]) {
                temp.push_back(nums[left]);
                left++;
            } else {
                temp.push_back(nums[right]);
                right++;
            }
        }
        while (left <= mid) {
            temp.push_back(nums[left]);
            left++;
        }
        while (right <= high) {
            temp.push_back(nums[right]);
            right++;
        }
        for (int i = low; i <= high; i++) {
            nums[i] = temp[i - low];
        }
    }
    int countPairs(vector<int>& nums, int low, 
    int mid, int high) {

        int right = mid + 1;
        int count = 0;

        for (int i = low; i <= mid; i++) {
            while (right <= high && (long long)nums[i] > 
            2LL * nums[right]) {
            right++;
        }
            count += (right - (mid + 1));
        }
        return count;
    }
    int solve(vector<int>& nums, int low, int high) {
        int count = 0;
        if (low >= high) {
            return count;
        }
        int mid = (low + high) / 2;
        count += solve(nums, low, mid);
        count += solve(nums, mid + 1, high);
        count += countPairs(nums, low, mid, high);
        merge(nums, low, mid, high);
        return count;
    }

    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        return solve(nums, 0, n - 1);
    }
};