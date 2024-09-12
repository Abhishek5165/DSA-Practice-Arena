// Better Approch : Giving TLE ...
// Time Complexity : Time Complexity: O(N*N * log(no. of unique triplets))

// Space Complexity: O(2 * no. of the unique triplets) + O(N) as we are using a set data structure and a list to store the triplets and extra O(N) for storing the array elements in another set.

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
    set<vector<int>>st;
    int n = nums.size();

    for(int i=0;i<n;i++){

    set<int>hashset;

    for(int j=i+1;j<n;j++){

    int third = -(nums[i] + nums[j]);

    if(hashset.find(third) != hashset.end()){
    vector<int>temp = {nums[i],nums[j],third};
    sort(begin(temp),end(temp));
    st.insert(temp);
    }
    hashset.insert(nums[j]);
    }
    }
    vector<vector<int>>ans(st.begin(),st.end());
    return ans;
    }
};


// Optimal Approch ....

// Time Complexity : O(NlogN)+O(N*N);
// Space Complexity : O(1); using some extra space for storing the ans..

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; i++) {
            if (i != 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int j = i + 1;
            int k = n - 1;
            while (j < k) {
                int sum = 0;
                sum += nums[i] + nums[j] + nums[k];
                if (sum < 0) {
                    j++;
                } else if (sum > 0) {
                    k--;
                } else {
                    vector<int> temp = {nums[i], nums[j], nums[k]};
                    j++;
                    k--;
                    ans.push_back(temp);
                    while (j < k && nums[j] == nums[j - 1]) {
                        j++;
                    }
                    while (j < k && nums[k] == nums[k + 1]) {
                        k--;
                    }
                }
            }
        }
        return ans;
    }
};