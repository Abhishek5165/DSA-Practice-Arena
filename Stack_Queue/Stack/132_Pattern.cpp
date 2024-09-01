//Approach-1
//T.C : O(n^3) - T.L.E : [94 / 103 test cases passed.]
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i<n; i++) {
            
            for(int j = i+1; j<n; j++) {
                
                if(nums[j] > nums[i]) {
                    
                    for(int k = j+1; k<n; k++) {
                        if(nums[i] < nums[k] && nums[k] < nums[j] )
                            return true;
                    }
                    
                }
            }
        }
        return false;
    }
};



//Approach-2
//T.C : O(n^2) - T.L.E : [101 / 103 test cases passed.]
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int min_i = INT_MAX;
        int n = nums.size();
        for(int j = 0; j<n-1; j++) {
            min_i = min(min_i, nums[j]);
            for(int k = j+1; k<n; k++) {
                if(min_i < nums[k] && nums[k] < nums[j])
                    return true;
            }
        }
        return false;
    }
};



// Most Optimize .....

// Time Complexity : O(N);
// Space Complexity : O(N);

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
    int num3 = INT_MIN;
    stack<int>st;
    int n = nums.size();

    for(int i=n-1;i>=0;i--){
    
    if(nums[i] < num3){
    return true;
    }
    while(!st.empty() && st.top() < nums[i]){
    num3 = st.top();
    st.pop();
    }
    st.push(nums[i]);
    }
    return false;
    }
};