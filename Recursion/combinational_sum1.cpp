// Time Complexity : O(2^t) + k (average length of combinations)

// where t is the target value divided by the minimum element in the candidates array (target / min(candidates))

// Space complexity : O(t / min(candidates));

class Solution {
public:
    void solve(int index,int target,vector<int>&candidates,
    vector<vector<int>>&ans,vector<int>&temp){
    int n = candidates.size();
    if(index == n){
    if(target == 0){
    ans.push_back(temp);
    }
    return;
    }
    if(candidates[index] <= target){
    temp.push_back(candidates[index]);
    solve(index,target-candidates[index],candidates,ans,temp);
    temp.pop_back();
    }
    solve(index+1,target,candidates,ans,temp);
    }

    vector<vector<int>> combinationSum
    (vector<int>& candidates, int target) {
    
    vector<vector<int>>ans;
    vector<int>temp;
    solve(0,target,candidates,ans,temp);
    return ans;
    }
};