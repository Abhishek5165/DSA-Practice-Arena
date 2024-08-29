// Time Complexity : O(N);
// Space Complexity : O(N);

class Solution {
  public:
    string postToInfix(string exp) {
      
    stack<string>st;
    
    int n = exp.size();
    
    for(int i=0;i<n;i++){
        
    char c = exp[i];
    
    if(c == '+' || c == '*' || c == '/' || c == '-'){
        
    string B = st.top();
    st.pop();
    
    string A = st.top();
    st.pop();
    
    st.push('(' + A + c + B + ')');
    }
    else{
    st.push(string(1,c));
    }
    }
    return st.top();
    }
};