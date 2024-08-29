// Time Complexity : O(N);
// Space Complexity : O(N);

class Solution {
  public:
    string preToPost(string pre_exp) {
        
    int n = pre_exp.size();
    int i = n-1;
    stack<string>st;
    
    while(i>=0){
    
    char ch = pre_exp[i];
    
    if(ch == '*' || ch == '/' || ch == '+' || ch == '-' || ch == '%'
    || ch == '^'){
    
    string s1 = st.top();
    st.pop();
    
    string s2 = st.top();
    st.pop();
    
    string ans = s1 + s2 + ch;
    st.push(ans);
    }
    else{
    st.push(string(1,ch));
    }
    i--;
    }
    return st.top();
    }
};