// Time Complexity : O(N*logN);
// Space Complexity : O(N);

class Solution
{
    public:
    int longestSubsequence(int n, int a[]){
    vector<int>temp;
    temp.push_back(a[0]);
    int len = 1;
    
    for(int i=1;i<n;i++){
    
    if(a[i] > temp.back()){
    temp.push_back(a[i]);
    len++;
    }
    else{
    int lower_index = lower_bound(temp.begin(),temp.end(),
    a[i])-temp.begin();
    temp[lower_index] = a[i];
    }
    }
    return len;
    }
};