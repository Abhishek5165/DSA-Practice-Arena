// Approch - 1 using recurrsion ....

// Time complexity : O(n*n) + O(n)
// Space complexity : O(1)

class Solution {
public:
    bool check(string& s, int i, int j) {

        while (i < j) {

            if (s[i] != s[j]) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    int countSubstrings(string s) {
        int count = 0;
        int n = s.size();

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {

                if (check(s, i, j)) {
                    count++;
                }
            }
        }
        return count;
    }
};


// Approch - 2 using memoization ....

// Time complexity : nearly O(n*n) because we check palindrome only once.
// Space complexity : O(n*n)


class Solution {
public:
    
    int t[1001][1001];

    bool check(string& s, int i, int j) {

    if(i > j){
    return true;
    }
    if(t[i][j] != -1){
    return t[i][j];
    }

    if(s[i] == s[j]){
    return t[i][j] = check(s,i+1,j-1);
    }
    return false;
    }

    int countSubstrings(string s) {
        memset(t,-1,sizeof(t));
        int count = 0;
        int n = s.size();

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {

                if (check(s, i, j)) {
                    count++;
                }
            }
        }
        return count;
    }
};


// Approch - 3 Bottom Up ... Blue Print for many other problems 

// Time complexity : nearly O(n*n)
// Space complexity : O(n*n)


class Solution {
public:
    bool t[1001][1001];
    int count = 0;

    int countSubstrings(string s) {
        int n = size(s);
        memset(t, false, sizeof(t));

        for (int length = 1; length <= n; length++) { 
            // 1 length sub,
            // 2 length and so on ...
            
            for (int i = 0; i + length - 1 < n; i++) {
                int j = i + length - 1;

                if (i == j) {
                    t[i][j] = true;
                } else if (i + 1 == j) {
                    t[i][j] = (s[i] == s[j]);
                } else if (s[i] == s[j] && t[i + 1][j - 1]) {
                    t[i][j] = true;
                }
                if (t[i][j] == true) {
                    count++;
                }
            }
        }
        return count;
    }
};


// Time complexity : nearly O(n*n)
// Space complexity : O(1)

// Smart approch just use the property of palindrome

class Solution {
public:
    void check(string s,int i,int j,int &count){
    int n = size(s);
    while(i>=0 && j<n && s[i] == s[j]){
    count++;
    i--;
    j++;
    }
    }
    int countSubstrings(string s) {
    int n = size(s);
    int count = 0;
    for(int i=0;i<n;i++){
    check(s,i,i,count);
    check(s,i,i+1,count);
    }
    return count;
    }
};