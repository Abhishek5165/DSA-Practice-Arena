// Time Complexity : O(5N);  ~= O(N);
// Space Complexity : O(5N); ~= O(N);


class Solution {
public:
     int mod = (int)(1e9+7);
    int n;
    vector<int>findNSE(vector<int>&arr){             // O(2N)
    stack<int>st;
    vector<int>NSE(n);

    for(int i=n-1;i>=0;i--){
    
    while(!st.empty() && arr[st.top()] >= arr[i]){
    st.pop();
    }
    NSE[i] = st.empty() ? n : st.top();
    st.push(i);
    }
    return NSE;
    }

    vector<int>findPSEE(vector<int>&arr){            // O(2N)

    stack<int>st;
    vector<int>PSEE(n);

    for(int i=0;i<n;i++){
    
    while(!st.empty() && arr[st.top()] > arr[i]){
    st.pop();
    }
    PSEE[i] = st.empty() ? -1 : st.top();
    st.push(i);
    }
    return PSEE;
    }
    int sumSubarrayMins(vector<int>& arr) {

    n = arr.size();

    vector<int> NSE = findNSE(arr);
    vector<int> PSEE = findPSEE(arr);

    int total = 0;

    for(int i=0;i<n;i++){                           // O(N)
    
    int Left = i - PSEE[i];
    int Right = NSE[i] - i;

    total = (total + (Left * Right * 1LL * arr[i])%mod)%mod;
    }
    return total;
    }
};