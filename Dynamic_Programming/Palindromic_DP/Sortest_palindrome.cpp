// Time Complexity : O(N^N);
// Space Complexity : O(N);   only recursion stack space....

class Solution {
public:
    string solve(string &s){
    int n = s.size();
    int i=0;
    int j = n-1;
    while(i < j){
    swap(s[i],s[j]);
    i++;
    j--;
    }
    return s;
    }
    
    string shortestPalindrome(string s) {

    int n = s.size();
    string start = s;

    int i = 0;

    for(int j=n-1;j>=0;j--){
    while(j >= 0 && start[i] == start[j]){
    i++;
    j--;
    }
    } 
    if(i == n){
    return start;
    }
    string p = start.substr(i);
    string remain = p;
    string ans = solve(remain) + 
    shortestPalindrome(start.substr(0,i)) + p;
    return ans;
    }
};