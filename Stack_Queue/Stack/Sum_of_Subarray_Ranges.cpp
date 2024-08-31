// Time Complexity : O(10N); ~= O(N);
// Space Complexity : O(10N); ~= O(N);

class Solution {
public:
    int n;
    // ---------------------------------------------------

    vector<long long>findNSE(vector<int>&arr){
    stack<int>st;
    vector<long long>NSE(n);

    for(int i=n-1;i>=0;i--){
    
    while(!st.empty() && arr[st.top()] >= arr[i]){
    st.pop();
    }
    NSE[i] = st.empty() ? n : st.top();
    st.push(i);
    }
    return NSE;
    }

 // ---------------------------------------------------

    vector<long long>findPSEE(vector<int>&arr){

    stack<int>st;
    vector<long long>PSEE(n);

    for(int i=0;i<n;i++){
    
    while(!st.empty() && arr[st.top()] > arr[i]){
    st.pop();
    }
    PSEE[i] = st.empty() ? -1 : st.top();
    st.push(i);
    }
    return PSEE;
    }

 // ---------------------------------------------------

    vector<long long>findNGE(vector<int>&arr){
    stack<int>st;
    vector<long long>NGE(n);

    for(int i=n-1;i>=0;i--){
    
    while(!st.empty() && arr[st.top()] <= arr[i]){
    st.pop();
    }
    NGE[i] = st.empty() ? n : st.top();
    st.push(i);
    }
    return NGE;
    }

     // ---------------------------------------------------


    vector<long long>findPGEE(vector<int>&arr){

    stack<int>st;
    vector<long long>PGEE(n);

    for(int i=0;i<n;i++){
    
    while(!st.empty() && arr[st.top()] < arr[i]){
    st.pop();
    }
    PGEE[i] = st.empty() ? -1 : st.top();
    st.push(i);
    }
    return PGEE;
    }

 // ---------------------------------------------------

    long long subArrayRanges(vector<int>& nums) {

    n = nums.size();
    long long minimums = 0;
    long long maximums = 0;


    vector<long long> NSE  = findNSE(nums);
    vector<long long> PSEE = findPSEE(nums);
    vector<long long> NGE  = findNGE(nums);
    vector<long long> PGEE = findPGEE(nums);

    for(int i=0;i<n;i++){

    long long Left = i - PSEE[i];
    long long Right = NSE[i] - i;
    long long Left1 = i - PGEE[i];
    long long Right1 = NGE[i] - i;

    minimums += (Left*Right*nums[i]);
    maximums += (Left1*Right1*nums[i]);
    }
    return abs(maximums - minimums);
    }
};