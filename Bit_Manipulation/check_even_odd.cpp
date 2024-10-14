// Time Complexity : O(1);
// Space Complexity : O(1);

// Approch - 1 Using And Operator...

class Solution {
  public:
    string oddEven(int n) {
    if(n&1){
    return "odd";
    }
    else{
    return "even";
    }
    }
};


// Approch - 2 Using Or Operator...


class Solution {
  public:
    bool isEven(int n){
    return ((n|1)>n) ? true : false;
    }
    string oddEven(int n) {
    if(isEven(n)){
    return "even";
    }
    else{
    return "odd";
    }
    }
};

// Approch - 3 Using LeftShift & RightShift Operator...

class Solution {
  public:
    string oddEven(int n) {
    if(((n>>1)<<1) == n){
    return "even";
    }
    else{
    return "odd";
    }
    }
};
