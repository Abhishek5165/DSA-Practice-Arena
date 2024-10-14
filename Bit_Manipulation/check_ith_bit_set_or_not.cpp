// Time Complexity : O(1);
// Space Complexity : O(1);

// Approch - 1 Using Left Shift Operator..

class Solution {
  public:
    bool checkKthBit(int n, int k) {
    if(((1<<k) & n) > 0){
    return true;
    } 
    else{
    return false;
    }
    }
};

// Approch - 2 Using Right Shift Operator..

class Solution {
  public:
    bool checkKthBit(int n, int k) {
    if(((n>>k) & 1) != 0){
    return true;
    } 
    else{
    return false;
    }
    }
};