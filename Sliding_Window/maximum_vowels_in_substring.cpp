// Time complexity : O(n);
// Space complexity : O(1);

class Solution {
public:
    bool isVowel(char ch) {

        if (ch == 'a' || ch == 'e' || ch == 'i' || 
        ch == 'o' || ch == 'u') {
            return true;
        }
        return false;
    }
    int maxVowels(string s, int k) {

        int n = s.size();
        int count = 0;
        int maxxi = 0;

        int i = 0;
        int j = 0;

        while (j < n) {

            if (isVowel(s[j])) {
                count++;
            }

            if (j - i + 1 == k) {
                maxxi = max(maxxi, count);

                if (isVowel(s[i])) {
                    count--;
                }
                i++;
            }
            j++;
        }
        return maxxi;
    }
};