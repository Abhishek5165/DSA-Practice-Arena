// Formula for calculating the gap .....
// Initial gap = ceil((size of arr1[] + size of arr2[]) / 2)

// Time Complexity: O((n+m)*log(n+m))
// Space Complexity : O(1);


class Solution {
public:
    void solve(vector<int>& nums1, vector<int>& nums2, int index1, int index2) {
        if (nums1[index1] > nums2[index2]) {
            swap(nums1[index1], nums2[index2]);
        }
    }

    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // Copy nums2 into the extra space at the end of nums1
        for (int i = 0; i < n; i++) {
            nums1[m + i] = nums2[i];
        }
        
        int size = n + m;
        int gap = (size / 2) + (size % 2);
        
        while (gap > 0) {
            int left = 0;
            int right = left + gap;

            while (right < size) {
                // Only comparing elements within nums1 after nums2 is merged into nums1
                if (nums1[left] > nums1[right]) {
                    swap(nums1[left], nums1[right]);
                }
                left++;
                right++;
            }

            if (gap == 1) {
                break;
            }
            gap = (gap / 2) + (gap % 2);
        }
    }
};
