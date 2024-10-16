// Time Complexity : O(N) + O(Nlog(logN)) + O(N); ~= O(Nlog(logN));
// Space Complexity : O(N);

class Solution {
public:
    int countPrimes(int n) {
        vector<int> vec(n);
        for (int i = 2; i < n; i++) {
            vec[i] = 1;
        }
        int count = 0;
        for (int i = 2; i*i < n; i++) {
            if (vec[i] == 1){
                for (int j = i*i; j < n; j += i) {
                    vec[j] = 0;
                }
            }
        }
        for (int i=2;i<n;i++) {
            if (vec[i] == 1) {
                count++;
            }
        }
        return count;
    }
};