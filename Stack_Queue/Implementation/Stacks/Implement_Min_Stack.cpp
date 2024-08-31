// Time Complexity : O(1);
// Space Complexity : O(2N);

class MinStack {
  stack < pair < int, int >> st;

  public:
    void push(int x) {
      int min;
      if (st.empty()) {
        min = x;
      } else {
        min = min(st.top().second, x);
      }
      st.push({x,min});
    }

  void pop() {
    st.pop();
  }

  int top() {
    return st.top().first;
  }

  int getMin() {
    return st.top().second;
  }
};


// Time Complexity: O(1)
// Space Complexity: O(N)


class MinStack {
long long mini;
stack<long long>st;

public:
    MinStack() {
    mini = INT_MAX; 
    }
    
    void push(int val) {
    long long value = val;
    if(st.empty()){
    st.push(value);
    mini = value;
    }
    else{
    if(value < mini){
    st.push(2 * value * 1LL - mini);
    mini = value;
    }
    else{
    st.push(value);
    }
    }
    }
    
    void pop() {
    if (st.empty()) return;
    long long el = st.top();
    st.pop();

    if (el < mini) {
      mini = 2 * mini - el;
    }
    }
    
    int top() {
    if(st.empty()) return -1;
    long long element = st.top();
    if(element < mini){
    return mini;
    }
    return element;
    }
    
    int getMin() {
    return mini;
    }
};
