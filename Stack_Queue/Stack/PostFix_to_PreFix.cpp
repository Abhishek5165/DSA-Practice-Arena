// Time Complexity : O(N);
// Space Complexity : O(N);

class Solution {
  public:
    string postToPre(string post_exp) {
    int i = 0;
    int n = post_exp.size();
    stack<string>st;
    while(i<n){
    
    char ch = post_exp[i];
    
    if(ch == '*' || ch == '/' || ch == '+' || ch == '-' || ch == '%'
    || ch == '^'){
    
    string s1 = st.top();
    st.pop();
    
    string s2 = st.top();
    st.pop();
    
    string ans = ch + s2 + s1;
    st.push(ans);
    }
    else{
    st.push(string(1,ch));
    }
    i++;
    }
    return st.top();
    }
};