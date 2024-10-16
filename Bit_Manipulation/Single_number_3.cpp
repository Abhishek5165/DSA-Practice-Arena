// Time Complexity : O(2N);
// Space Complexity : O(1);

class Solution{
    public:
    vector<long long int> twoOddNum(long long int Arr[], 
    long long int N)  {
    long long XOR  = 0;
    long long B1 = 0,B2 = 0;
    
    for(int i=0;i<N;i++){
    XOR = XOR^Arr[i];
    }
    long long rightMostBit = (XOR&(XOR-1))^XOR;
    for(int i=0;i<N;i++){
 
    if(rightMostBit&Arr[i]){
    B1 = B1^Arr[i];
    }
    else{
    B2 = B2^Arr[i];
    }
    }
    if(B1<B2){
    return {B2,B1};
    }
    else{
    return {B1,B2};
    }
    }
};
