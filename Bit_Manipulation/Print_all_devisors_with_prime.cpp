class Solution{
	public:
	vector<int>AllPrimeFactors(int N) {
    vector<int>ans;
    for(int i=2;i<=N;i++){
    if(N%i == 0){
    ans.push_back(i);
    
    while(N%i == 0){
    N = N/i;
    }
    }
    }
    return ans;
	}
};

// run the for loop till the sqrt(N)...

class Solution{
	public:
	vector<int>AllPrimeFactors(int N) {
    vector<int>ans;
    for(int i=2;i*i<=N;i++){
    if(N%i == 0){
    ans.push_back(i);
    
    while(N%i == 0){
    N = N/i;
    }
    }
    }
    if(N > 1){
    ans.push_back(N);
    }
    return ans;
	}
};