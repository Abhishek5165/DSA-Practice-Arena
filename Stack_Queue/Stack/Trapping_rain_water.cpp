// Using Prefix & Suffix Sum...
// Time Complexity : O(3N);
// Space Complexity : O(2N);

class Solution {

public:
    vector<int> getLeftMax(vector<int> &height, int &n) {

        vector<int> leftMax(n);

        leftMax[0] = height[0];

        for (int i = 1; i < n; i++) {
            leftMax[i] = max(leftMax[i - 1], height[i]);
        }
        return leftMax;
    }

    vector<int> getRightMax(vector<int> &height, int &n) {

        vector<int> rightMax(n);

        rightMax[n - 1] = height[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            rightMax[i] = max(rightMax[i + 1], height[i]);
        }
        return rightMax;
    }

public:
    int trap(vector<int>& height) {

        int n = height.size();

        int sum = 0;

        vector<int> left = getLeftMax(height, n);
        vector<int> right = getRightMax(height, n);

        for (int i = 0; i < n; i++) {

            int h = min(left[i], right[i]) - height[i];
            sum += h;
        }
        return sum;
    }
};


// Using Stack....


//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        stack<int> st;
        int water = 0;

        for(int i = 0; i < n; i++) {
            //This is actually the concept of monotonic stack
            while(!st.empty() && height[i] > height[st.top()]) {
                //It means "mid" is bounded from left (i.e. height[st.top()]) and right(i.e. height[i])
                int mid = st.top();
                st.pop();

                //But, for bounding mid, we need left (height[st.top()])
                if(st.empty()) {
                    break; //no left bound found
                }
                
                int right = i;
                int left  = st.top();

                int h = min(height[right], height[left]) - height[mid];
                int w = right - left - 1;
                
                water += (h*w);
            }
            st.push(i);
        }

        return water;
    }
};

// Optimize .....

// Time Complexity : O(N);
// Space Complexity : O(1);

class Solution {
public:
    int trap(vector<int>& height) {
    int n = height.size();
    int left = 0;
    int right = n-1;
    int leftbar = height[0];
    int rightbar = height[n-1];  
    int ans = 0;
    
    while(left <= right){
    
    if(leftbar < rightbar){
    
    if(height[left] > leftbar){
    leftbar = height[left];
    }
    else{
    ans += leftbar - height[left];
    left++;
    }
    }
    else{
    if(height[right] > rightbar){
    rightbar = height[right];
    }
    else{
    ans += rightbar - height[right];
    right--;
    }
    }
    }
    return ans;
    }
};