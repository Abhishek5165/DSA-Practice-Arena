// Time Complexity : O(1);
// Space Complexity : O(N);

class MyStack {
queue<int>Q;
public:
    MyStack() {
        
    }
    void push(int x) {
    int size = Q.size();
    Q.push(x);
    for(int i=0;i<size;i++){
    int element = Q.front();
    Q.push(element);
    Q.pop();
    }
    }
    
    int pop() {
    int n = Q.front();
    Q.pop();
    return n;
    }
    
    int top() {
    return Q.front(); 
    }
    
    bool empty() {
    return Q.empty(); 
    }
};