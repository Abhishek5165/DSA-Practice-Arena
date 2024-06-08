// Kadane's Algorithm, maximum subarray sum

// TC : O(n^2) 
// SC : O(1)

int maxSubarraySum(int arr[], int n) {
    int maxi = INT_MIN; // maximum sum

    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            // current subarray = arr[i.....j]

            //add the current element arr[j]
            // to the sum i.e. sum of arr[i...j-1]
            sum += arr[j];

            maxi = max(maxi, sum); // getting the maximum
        }
    }

    return maxi;
}

// ------------------------------------------------------------------------


// Approch - 2 Kadane's Algorithm.

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
    int maxxi = nums[0];
    int sum = 0;
    int n = nums.size();

    for(int i=0;i<n;i++){
    
    sum += nums[i];
    maxxi = max(maxxi,sum);

    if(sum < 0){
    sum = 0;
    }
    }
    return maxxi;
    }
};

// --------------------------------------------------------------------


// Printing the subarry with maximum sum (multiple posible)

// Time Complexity: O(N), where N = size of the array.
// Reason: We are using a single loop running N times.

// Space Complexity: O(1) as we are not using any extra space.


long long maxSubarraySum(int arr[], int n) {
    long long maxi = LONG_MIN; // maximum sum
    long long sum = 0;

    int start = 0;
    int ansStart = -1, ansEnd = -1;
    for (int i = 0; i < n; i++) {

        if (sum == 0) start = i; // starting index

        sum += arr[i];

        if (sum > maxi) {
            maxi = sum;

            ansStart = start;
            ansEnd = i;
        }

        // If sum < 0: discard the sum calculated
        if (sum < 0) {
            sum = 0;
        }
    }

    //printing the subarray:
    cout << "The subarray is: [";
    for (int i = ansStart; i <= ansEnd; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";

    // To consider the sum of the empty subarray
    // uncomment the following check:

    //if (maxi < 0) maxi = 0;

    return maxi;
}