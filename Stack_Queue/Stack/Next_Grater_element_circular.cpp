// Time Complexity : O(4N);
// Space Complexity : O(2N);

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
    stack<int>st;
    int n = nums.size();
    vector<int>ans;

    for(int i=2*n-1;i>=0;i--){
    
    while(!st.empty() && st.top() <= nums[i%n]){
    st.pop();
    }
    if(i<n){
    if(st.empty()){
    ans.insert(ans.begin(),-1);
    }
    else{
    ans.insert(ans.begin(),st.top());
    }
    }
    st.push(nums[i%n]);
    } 
    return ans;  
    }
};