// Time Complexity : O(N);
// Space Complexity : O(1);

class Solution {
  public:
    int lps(string str){
        
    int n = str.size();
    int i=0,j=1,k=0,c=0;
    
    while(i < n && j < n){
    if(str[i] == str[j]){
    i++;
    j++;
    c++;
    }
    else{
    i=0;
    c=0;
    k++;
    j = k;
    }
    }
    return c;
    }
};