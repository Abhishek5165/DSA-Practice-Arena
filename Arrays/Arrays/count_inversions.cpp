// Time Complexity : O(N*N);
// Space Complexity : O(1);

// Brute Force ....

class Solution {
  public:
    long long int inversionCount(vector<long long> &arr) {
    
    long long count = 0;
    int n = arr.size();
    for(int i=0;i<n;i++){
        
    for(int j=i+1;j<n;j++){
    if(arr[i] > arr[j]){
    count++;
    }
    }
    }
    return count;
    }
};

// Otimal Approch ....

// Time Complexity: O(N*logN);
// Space Complexity : O(N);

class Solution {
  public:
    long long merge(vector<long long>&arr,int low,int mid,int high){
    
    vector<int>temp;
    int left = low;
    int right = mid+1;
    long long count = 0;
    while(left <= mid && right <= high){
    
    if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        }
        else {
            temp.push_back(arr[right]);
            count += (mid - left + 1); //Modification 2
            right++;
        }
    }
    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }

    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }
    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
    return count; 
    }
    
    long long solve(vector<long long>&arr,int low,int high){
        
    long long count = 0;
 
    if(low >= high){
    return count;
    }
    
    long long mid = (low+high)/2;
    
    count += solve(arr,low,mid);
    count += solve(arr,mid+1,high);
    count += merge(arr,low,mid,high);
    
    return count;
    }
    
    long long int inversionCount(vector<long long> &arr){
    int n = arr.size();
    return solve(arr,0,n-1);
    }
};