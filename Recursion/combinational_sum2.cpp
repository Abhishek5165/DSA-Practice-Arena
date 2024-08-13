// This is similar to the combinational 2 but here the index should be increases in both the cases ans for dublicacy we required set data structure to store the temp values;


// Another method efficient ....

// Time Complexity : O(nlogn + 2^n.k);
// Space Complexity : O(n+L.k);

// where L is the total number of valid combinations and k is the average length of each combination.


class Solution {
public:
    void solve(int index,int target,vector<int>&candidates,
    vector<int>&temp,vector<vector<int>>&ans){
    
    int n = candidates.size();
    if(target == 0){
    ans.push_back(temp);
    }

    for(int i=index;i<n;i++){
    if(i > index && candidates[i] == candidates[i-1]) continue;
    if(candidates[i] > target) break;
    temp.push_back(candidates[i]);
    solve(i+1,target-candidates[i],candidates,temp,ans);
    temp.pop_back();
    }
    }
    vector<vector<int>> combinationSum2(vector<int>& 
    candidates, int target) {
    sort(candidates.begin(),candidates.end());
    vector<vector<int>>ans;
    vector<int>temp;
    solve(0,target,candidates,temp,ans);
    return ans;
    }
};

