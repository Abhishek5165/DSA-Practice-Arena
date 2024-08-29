// Time Complexity : O(N); where N is the Length of string s
// Space Complexity : O(N);

class Solution {
public:
    bool isValid(string s) {
    stack<char>st;
    for(int i=0;i<s.size();i++){
    if(s[i] == '(' || s[i] == '{' || s[i] == '['){
    st.push(s[i]);
    }
    else{
    if(st.empty() == true){
    return false;
    }
    char ch = st.top();
    st.pop();
    if(s[i] == ')' && ch == '(' || s[i] == '}' &&
    ch == '{' || s[i] == ']' && ch == '['){
    continue;
    }
    else{
    return false;
    }
    }
    }    
    return st.empty();
    }
};
