// TLE for big integers

// time complexity -> O(n)
// space complexity -> O(1)

class Solution {
public:
    double myPow(double x, int n) {
     double sum = 1.0;
     long long num = n;

     if(num<0) {
     num = -1 * num;
     }
     for(int i=0;i<num;i++){
     sum *= x;
     }
     if(n<0) sum = (double)(1.0)/(double)(sum);
     return sum;
    }
};


// Approch - 2 

// time complexity -> O(log2n)
// space complexity -> O(1)

class Solution {
public:
    double myPow(double x, int n) {
     double sum = 1.0;
     long long num = n;

     if(num<0) {
     num = -1 * num;
     }
     while(num!=0){

     if(num&1){

     sum *= x;
     num = num-1;
     }
     else{

     x *= x;
     num = num/2;
     }
     }
     if(n<0) sum = (double)(1.0)/(double)(sum);
     return sum;
    }
};