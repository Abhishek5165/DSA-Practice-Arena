// Time Complexity : O(N);
// Space Complexity : O(N);

class Solution {
public:
    int findTheLongestSubstring(string s) {
    int n = s.size();
    unordered_map<string,int>mpp;
    vector<int>vowels(5,0);
    string start = "00000";
    mpp[start] = -1;
    int ans = 0;

    for(int i=0;i<n;i++){
    if(s[i] == 'a'){
    vowels[0] = (vowels[0]+1)%2;
    }
    if(s[i] == 'e'){
    vowels[1] = (vowels[1]+1)%2;
    }
    if(s[i] == 'i'){
    vowels[2] = (vowels[2]+1)%2;
    }
    if(s[i] == 'o'){
    vowels[3] = (vowels[3]+1)%2;
    }
    if(s[i] == 'u'){
    vowels[4] = (vowels[4]+1)%2;
    }
    start = "";
    for(int i=0;i<5;i++){
    start += to_string(vowels[i]);
    }
    if(mpp.find(start) != mpp.end()){
    ans = max(ans,i-mpp[start]);
    }
    else{
    mpp[start] = i;
    }
    } 
    return ans;  
    }
};

// Time Complexity : O(N);
// Space Complexity : O(1);

class Solution {
public:
    int findTheLongestSubstring(string s) {
    int n = s.size();
    int mask = 0;
    unordered_map<int,int>mpp;
    mpp[mask] = -1;
    int ans = 0;

    for(int i=0;i<n;i++){
    if(s[i] == 'a'){
    mask = mask ^ (1<<1);
    }
    if(s[i] == 'e'){
    mask = mask ^ (1<<2);
    }
    if(s[i] == 'i'){
    mask = mask ^ (1<<3);
    }
    if(s[i] == 'o'){
    mask = mask ^ (1<<4);
    }
    if(s[i] == 'u'){
    mask = mask ^ (1<<5);
    }
    if(mpp.find(mask) != mpp.end()){
    ans = max(ans,i-mpp[mask]);
    }
    else{
    mpp[mask] = i;
    }
    }
    return ans;
    }
};