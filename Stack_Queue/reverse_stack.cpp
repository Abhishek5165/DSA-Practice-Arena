
// TC : O(n^2)
// SC : O(N)
// AS : O(N)

// Additional Auxilary Space

class Solution{
public:
    void Reverse(stack<int> &St){
        
    if(St.empty() == true) {
    return;
    }
    int top = St.top();
    St.pop();
    
    Reverse(St);
    
    stack<int>temp;
    
    while(!St.empty()){
        
    temp.push(St.top());
    St.pop();
    }
    St.push(top);
    while(!temp.empty()){
        
    St.push(temp.top());
    temp.pop();
    }
    }
};


// Reduce the Auxilary space to O(1)
// SC : O(1)


class Solution{
public:
    
    void insert(stack<int>&st,int top){
        
    if(st.empty()){
    st.push(top);
    return;
    }
    int element = st.top();
    st.pop();
    insert(st,top);
    st.push(element);
    }
    void Reverse(stack<int> &St){
    
    if(St.empty()){
    return;
    }
    int top = St.top();
    St.pop();
    
    Reverse(St);
    insert(St,top);
    }
};