// There are 2 methods to solve this questions ................
// First is using the LCS code...

// step 1 = reverse the given string
// step 2 =  and then find the LCS of string and after reverseing strength.....
// hence this the ans.....

// -----------------------------------------------------------------------

// using the second approch ..... using Memoization .....

// Time complexity : O(N*N) + O(N);
// Space complexity : O(N*N);

class Solution {
public:
    int t[1001][1001];

    int solve(string &s, int i, int j) {
        if (i > j) {
            return 0;
        }
        if (i == j) {
            return 1;
        }
        if (t[i][j] != -1) {
            return t[i][j];
        }
        if (s[i] == s[j]) {
            return t[i][j] = 2 + solve(s, i + 1, j - 1);
        }
        return t[i][j] = max(solve(s, i + 1, j), solve(s, i, j - 1));
    }

    int longestPalindromeSubseq(string s) {
        int n = size(s);
        memset(t, -1, sizeof(t));
        return solve(s, 0, n - 1);
    }
};

// Using Blue Print ......

// Time complexity : O(n*n);
// Space complexity : O(n*n);



class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = size(s);

        vector<vector<int>> t(n, vector<int>(n, 0));

        for (int i = 0; i < n; i++) {
            t[i][i] = 1;
        }
        for (int L = 2; L <= n; L++) {

            for (int i = 0; i + L - 1 < n; i++) {

                int j = i + L - 1;

                if (s[i] == s[j]) {
                    t[i][j] = 2 + t[i + 1][j - 1];
                } else {
                    t[i][j] = max(t[i + 1][j], t[i][j - 1]);
                }
            }
        }
        return t[0][n - 1];
    }
};