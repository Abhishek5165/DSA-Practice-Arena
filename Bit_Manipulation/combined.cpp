
// Clear the ith bit..
// Set the ith bit..
// return the ith bit..

class Solution {
  public:
    void bitManipulation(int num, int i) {
    int k = i-1;
    int clear = (num&(~(1<<k)));
    int set = (num|(1<<k));
    int get = (num&(1<<k)) ? 1 : 0;
    
    cout<<get<<" "<<set<<" "<<clear;
    }
};