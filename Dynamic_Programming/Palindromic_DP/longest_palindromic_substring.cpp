// Time complexity : O(N*N + N);
// Space complexity : O(N*N);

class Solution {
public:
    bool t[1001][1001];

    bool check(string s, int i, int j) {

        if (i >= j) {
            return true;
        }
        if (t[i][j] != false) {
            return t[i][j];
        }
        if (s[i] == s[j]) {
            return t[i][j] = check(s, i + 1, j - 1);
        }
        return false;
    }
    string longestPalindrome(string s) {

        int n = s.size();
        memset(t, false, sizeof(t));

        int start = -1;
        int maxLength = INT_MIN;

        for (int i = 0; i < n; i++) {

            for (int j = i; j < n; j++) {

                if (check(s, i, j) == true) {
                    if (j - i + 1 > maxLength) {
                        maxLength = j - i + 1;
                        start = i;
                    }
                }
            }
        }
        return s.substr(start, maxLength);
    }
};

// Using Blue Print ....

// Time complexity : O(N^N);
// Space complexity : O(N*N);


class Solution {
public:
    bool t[1001][1001];

    string longestPalindrome(string s) {

        int n = s.size();
        memset(t, false, sizeof(t));

        int maxLength = INT_MIN;
        int start = 0;

        for (int L = 1; L <= n; L++) {

            for (int i = 0; i + L - 1 < n; i++) {
                int j = i + L - 1;

                if (i == j) {
                    t[i][j] = true;
                } 
                else if (i + 1 == j) {
                    t[i][j] = (s[i] == s[j]);
                } 
                else if (s[i] == s[j] && t[i + 1][j - 1]) {
                    t[i][j] = true;
                }
                if (t[i][j] && j - i + 1 > maxLength) {
                    maxLength = j - i + 1;
                    start = i;
                }
            }
        }
        return s.substr(start, maxLength);
    }
};