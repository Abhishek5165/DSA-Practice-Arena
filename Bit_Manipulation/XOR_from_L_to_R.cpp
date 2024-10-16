class Solution {
  public:
  
    // This function returns the XOR from 1 to N...

    int XOR(int N){
    int temp = 0;
    if(N%4 == 1){
    temp = 1;
    }
    else if(N%4 == 2){
    temp = N+1;
    }
    else if(N%4 == 3){
    temp = 0;
    }
    else{
    temp = N;
    }
    return temp;
    }
    int findXOR(int l, int r) {
    int XORL = XOR(l-1);
    int XORR = XOR(r);
    
    return XORR^XORL;
    }
};