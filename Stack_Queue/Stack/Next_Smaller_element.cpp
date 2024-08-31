// Time Complexity : O(2N);
// Space Complexity : O(N);

vector<int> Solution::prevSmaller(vector<int> &A) {

int n = A.size();
stack<int>st;
vector<int>ans;

for(int i=0;i<n;i++){
while(!st.empty() && st.top() >= A[i]){
st.pop();
}
if(st.empty()){
ans.push_back(-1);
}
else{
ans.push_back(st.top());
}
st.push(A[i]);
}
return ans;
}
