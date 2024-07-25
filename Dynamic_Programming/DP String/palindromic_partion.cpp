// Time complexity : O(2^N * N);
// Space complexity : O(1);

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