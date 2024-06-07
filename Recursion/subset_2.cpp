
// Backtracking (Recursive Approach)🤓:  TC - O(n^2 * n)

class Solution {
public:
    void solve(vector<vector<int>>& ans,
     vector<int> &nums, vector<int> &temp,int index) {

        ans.push_back(temp);

        for(int i=index;i<nums.size();i++){

        if(i != index && nums[i] == nums[i-1]) continue;

        temp.push_back(nums[i]);
        solve(ans, nums, temp, i + 1);
        temp.pop_back();
    }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

    vector<vector<int>>ans;
    vector<int>temp;

    sort(nums.begin(),nums.end());
    solve(ans,nums,temp,0);
    return ans;
    }
};
