// Better Approch .....

// Time Complexity : O(N*N);
// Space Complexity : O(N);

// Giving TLE for Larger TestCases....

int subarraysWithSumK(vector < int > a, int b) {
int count = 0;
int n = a.size();
for(int i=0;i<n;i++){
int XOR = 0;
for(int j=i;j<n;j++){
XOR = XOR ^ a[j];

if(XOR == b){
count++;
}
}
}
return count;
}


// Optimal Approch ...

// Time Complexity: O(N) or O(N*logN);
// Space Complexity : O(N);

int Solution::solve(vector<int> &A, int B) {
int XOR = 0;
int count = 0;
int n = A.size();
unordered_map<int,int>mpp;
mpp[0] = 1;
for(int i=0;i<n;i++){
    
XOR = XOR ^ A[i];
int rem = XOR ^ B;
count += mpp[rem];
mpp[XOR]++;
}
return count;
}

