// Time Complexity : O(sqrt(n));
// Space Complexity : O(1);

class Solution{
public:
    int isPrime(int N){
    bool flag = true;
    if(N<=1){
    flag = false;
    }
    else{
    for(int i=2;i*i<=N;i++){
    if(N%i == 0){
    flag = false;
    }
    }
    }
    return flag == true;
    }
};

// Giving TLE ... but one of the way ..

class Solution{
public:
    int isPrime(int N){
    bool flag = true;
    if(N<=1){
    flag = false;
    }
    else{
    for(int i=2;i<=N/2;i++){
    if(N%i == 0){
    flag = false;
    }
    }
    }
    return flag == true;
    }
};