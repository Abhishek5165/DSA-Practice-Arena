// Expected Time Complexity: O(N);
// Expected Auxiliary Space: O(N);

class Solution{
    public:
    vector<int> help_classmate(vector<int> arr, int n){ 
    vector<int>ans(n);
    stack<int>st;
    for(int i=n-1;i>=0;i--){
    
    while(!st.empty() && st.top() >= arr[i]){
    st.pop();
    }
    ans[i] = st.empty() ? -1 : st.top();
    st.push(arr[i]);
    }
    return ans;
    } 
};