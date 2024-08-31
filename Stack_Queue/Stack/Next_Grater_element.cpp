// Time Complexity : O(2N);
// Space Complexity : O(N);

class Solution
{
    public:
    vector<long long> nextLargerElement(vector<long long> arr, int n){
        
    vector<long long>ans;
    stack<long long>st;

    for(int i=n-1;i>=0;i--){
    
    while(!st.empty() && arr[i] >= st.top()){
    st.pop();
    }
    if(st.empty()){
    ans.insert(ans.begin(),-1);
    }
    else{
    ans.insert(ans.begin(),st.top());
    }
    st.push(arr[i]);
    }
    return ans;
    }
};