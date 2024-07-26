// Approch - 1 Using Memoization.

// Time complexity : O(n*k);
// Space complexity : O(n*k);

class Solution {
public:
    int temp[501];

    int solve(int index, vector<int>& arr, int k) {

        int n = arr.size();
        int result = 0;
        int currMax = -1;

        if (index >= n)
            return 0;

        if (temp[index] != -1) {
            return temp[index];
        }

        for (int j = index; j < n && (j - index + 1) <= k; j++) {
            currMax = max(currMax, arr[j]);
            result =  max(result, (j - index + 1) * currMax 
            + solve(j + 1, arr, k));
        }
        return temp[index] = result;
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        memset(temp, -1, sizeof(temp));
        return solve(0, arr, k);
    }
};

// Approch - 2 Using Bottom Up.

// Time complexity : O(n*k);
// Space complexity : O(n*k);

class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {

    int n = arr.size();
    vector<int>T(n+1,0);

    for(int i=1;i<=n;i++){
    int currMax = -1;
    for(int j=1;j<=k && (i-j) >= 0;j++){
    currMax = max(currMax,arr[i-j]);
    T[i] = max(T[i],(currMax*j) + T[i-j]);
    }
    }
    return T[n];   
    }
};