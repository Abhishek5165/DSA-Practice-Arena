// Time Complexity : O(N); By using Shifting ....
// Space Complexity : O(1);

vector<int> rotateArray(vector<int>& arr, int n) {
int num = arr[0];
for(int i=0;i<n-1;i++){
arr[i] = arr[i+1];
}
arr[n-1] = num;
return arr;
}
