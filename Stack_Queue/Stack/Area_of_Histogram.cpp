// Time Complexity : O(5N);
// Space Complexity : O(4N);

class Solution {
public: 
    int n;
    vector<int>findPSE(vector<int>&nums){
    stack<int>st;
    vector<int>PSE(n);

    for(int i=0;i<n;i++){
    while(!st.empty() && nums[st.top()] >= nums[i]){
    st.pop();
    }
    PSE[i] = (st.empty()) ? -1 : st.top();
    st.push(i);
    }
    return PSE;
    }
    vector<int>findNSE(vector<int>&nums){
    
    stack<int>st;
    vector<int>NSE(n);
    
    for(int i=n-1;i>=0;i--){
    while(!st.empty() && nums[st.top()] >= nums[i]){
    st.pop();
    }
    NSE[i] = (st.empty()) ? n : st.top();
    st.push(i);
    }
    return NSE;
    }

    int largestRectangleArea(vector<int>& heights) {
    n = heights.size();

    vector<int> PSE = findPSE(heights);
    vector<int> NSE = findNSE(heights);

    int Area = 0;
    for(int i=0;i<n;i++){
    int H = heights[i];
    int W = NSE[i] - PSE[i] - 1; 
    int A = H * W;
    Area = max(Area,A);
    }
    return Area;
    }
};


// Time Complexity : O(N) + O(N);
// Space Complexity : O(N);


class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
    stack<int>st;

    int Area = 0;
    int nse = 0;
    int pse = 0;
    int element = 0;

    int n = heights.size();

    for(int i=0;i<n;i++){
    while(!st.empty() && heights[st.top()] > heights[i]){
    element = heights[st.top()];
    st.pop();
    nse = i;
    pse = st.empty() ? -1 : st.top();

    Area =  max(Area,(element * (nse-pse-1)));
    }
    st.push(i);
    }  
    while(!st.empty()){
    nse = n;
    element = heights[st.top()];
    st.pop();
    pse = st.empty() ? -1 : st.top();
    Area =  max(Area,(element * (nse-pse-1)));
    }
    return Area;
    }
};