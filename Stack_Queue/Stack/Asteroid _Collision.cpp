// Time Complexity : O(N);
// Space Complexity : O(N);

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
    int n = asteroids.size();
    stack<int>st;

    for(int i=0;i<n;i++){
    while(!st.empty() && asteroids[i] < 0 && st.top() > 0){
    
    int sum = st.top() + asteroids[i];
    if(sum > 0){
    asteroids[i] = 0;
    }
    else if(sum < 0){
    st.pop();
    }
    else{
    st.pop();
    asteroids[i] = 0;
    }
    }
    if(asteroids[i] != 0){
    st.push(asteroids[i]);
    }
    }
    int s = st.size();
    vector<int>ans(s);
    int i = s-1;
    while(!st.empty()){
    ans[i] = st.top();
    st.pop();
    i--;
    }
    return ans;
    }
};