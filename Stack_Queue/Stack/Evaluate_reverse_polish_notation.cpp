// Time Complexity : O(N);
// Space Complexity : O(N);

class Solution {
public:
    int solve(int A, int B,string op){
    
    if(op == "+"){
    return A + B;
    }
    else if(op == "-"){
    return A - B;
    }
    else if(op == "*"){
    return (long)A * (long)B;
    }
    else if(op == "/"){
    return A/B;
    }
    return -1;
    }
    int evalRPN(vector<string>& tokens) {

    int i=0;
    int n = tokens.size();

    stack<int>st;

    while(i < n){

    string ch = tokens[i];

    if(ch == "*" || ch == "/" || ch == "+" || ch == "-"){
    
    int b = st.top();
    st.pop();

    int a = st.top();
    st.pop();

    int ans = solve(a,b,ch);

    st.push(ans);
    }
    else{
    st.push(stoi(ch));
    }
    i++;
    } 
    return st.top();  
    }
};
