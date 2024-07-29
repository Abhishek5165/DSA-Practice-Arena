// Using Backtracking ....

// Time complexity : O(2*n) + O(n);
// Space complexity : O(n*n);

class Solution {
public:
    bool isPalindrome(string s, int start, int end) {

        while (start < end) {

            if (s[start] != s[end]) {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }

    void backTrack(string& s, int index, vector<string>& ans,
                   vector<vector<string>>& result) {
        int n = s.size();

        if (index == n) {
            result.push_back(ans);
        }

        for (int i = index; i < n; i++) {

            if (isPalindrome(s, index, i)) {
                ans.push_back(s.substr(index, i - index + 1));
                backTrack(s, i + 1, ans, result);
                ans.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {

        int n = s.size();
        vector<vector<string>> result;
        vector<string> ans;

        backTrack(s, 0, ans, result);

        return result;
    }
};


// Using blue Print ....

// Time complexity : O(2^n);
// Space complexity : O(n*n);


class Solution {
public:

void solve(string &s, int i, 
vector<string>& currPartition, 
vector<vector<bool>>& t, vector<vector<string>>& result) {
    
    if(i == s.length()) { 
        result.push_back(currPartition);
        return;
    }
    for(int j = i; j < s.length(); j++) {
            if(t[i][j] == true) {
                currPartition.push_back(s.substr(i, j-i+1));
                solve(s, j+1, currPartition, t, result);
                currPartition.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {

    int n = s.length();
    vector<vector<bool>> t(n, vector<bool>(n, false));

    for (int i = 0; i < n; ++i) {
        t[i][i] = true;
    }
    for (int L = 2; L <= n; ++L) {
            for (int i = 0; i < n - L + 1; ++i) {
                int j = i + L - 1;
                if (s[i] == s[j]) {
                    if (L == 2) {
                        t[i][j] = true;
                    } else {
                        t[i][j] = t[i + 1][j - 1];
                    }
                }
        }
    }
    vector<string> currPartition;
    vector<vector<string>>result;
    solve(s, 0, currPartition, t, result);
    return result; 
    }
};