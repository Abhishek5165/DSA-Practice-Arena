// Time Complexity : o(N);
// Space Complexity : O(no. of digits in a number); no. of digits = (longn)

class Solution {
public:
    void solve(int currNum,int limit,vector<int>&ans){
    if(currNum > limit){
    return;
    }
    ans.push_back(currNum);
    for(int append=0;append<=9;append++){
    int newNum = (currNum*10 + append);
    if(newNum > limit){
    return;
    }
    solve(newNum,limit,ans);
    }
    }

    vector<int> lexicalOrder(int n) {
    vector<int>ans;
    for(int i=1;i<=9;i++){
    solve(i,n,ans);
    }
    return ans;
    }
};