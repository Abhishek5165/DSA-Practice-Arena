// Using Hashing ....

// Time Complexity : O(2N);
// Space Complexity : O(N);

class Solution {
  public:
    vector<int> findTwoElement(vector<int> arr) {
    int n = arr.size();
    int hash[n + 1] = {0}; 

    for (int i = 0; i < n; i++) {
        hash[arr[i]]++;
    }

    int repeating = -1, missing = -1;
    
    for (int i = 1; i <= n; i++) {
        if (hash[i] == 2) repeating = i;
        else if (hash[i] == 0) missing = i;

        if (repeating != -1 && missing != -1)
            break;
    }
    return {repeating, missing};
    }
};

// Optimal Approch ..... Using Equations ...

// Time Complexity : O(N);
// Space Complexity : O(1);

vector<int> findMissingRepeatingNumbers(vector<int> a) {
    long long n = a.size();
    long long Sum = (n * (n + 1)) / 2;
    long long SumSquare = (n * (n + 1) * (2 * n + 1)) / 6;

    long long S = 0, SSq = 0;

    for(int i = 0; i < n; i++) {
        S += a[i];
        SSq += (long long)a[i] * (long long)a[i];
    }

    long long val1 = S - Sum; 
    long long val2 = SSq - SumSquare;

    val2 = val2 / val1;

    long long X = (val1 + val2) / 2;
    long long Y = X - val1;

    return {(int)X, (int)Y};
}
