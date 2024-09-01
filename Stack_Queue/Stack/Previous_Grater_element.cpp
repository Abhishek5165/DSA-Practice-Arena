// Time Complexity : O(N);
// Space Cpmplexity : O(N);

class Solution {
public:
    vector<int> PGE(vector<int>& nums) {
    stack<int>st;
    int n = nums.size();
    
    vector<int>ans(n);

    for(int i=0;i<n;i++){
    while(!st.empty() && st.top() < nums[i]){
    st.pop();
    }
    ans[i] = (st.empty()) ? -1 : st.top();
    st.push(nums[i]);
    }  
    return ans;
    }
};
