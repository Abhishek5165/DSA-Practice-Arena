// Time Complexity : O(1);
// Space Complexity : O(N);

class MyStack {

queue<int>Q1;
queue<int>Q2;

public:
    MyStack() {
        
    }
    
    void push(int x) {
    while(!Q1.empty()){
    Q2.push(Q1.front());
    Q1.pop();
    }
    Q1.push(x);
    while(!Q2.empty()){
    Q1.push(Q2.front());
    Q2.pop();
    }
    }
    
    int pop() {
    int element = Q1.front();
    Q1.pop();
    return element; 
    }
    
    int top() {
    return Q1.front();
    }
    
    bool empty() {
    return Q1.empty();  
    }
};