// Time Complexity : O(d) + O(n-d) + O(d);  ~= O(n-d)
// Space Complexity : O(d);

class Solution{
    public:
    void rotateArr(int arr[], int d, int n){
        
    vector<int>temp(d);
 
    d = d % n;
    // Step - 1  storing k elements .....

    for(int i=0;i<d;i++){
    temp[i] = arr[i];
    }
    
    // Step - 2 shifting ......

    for(int i=0;i<n-d;i++){
    arr[i] = arr[i+d];
    }

    // Step - 3 reassigning ......

    for(int i=n-d;i<n;i++){
    arr[i] = temp[i-n+d];
    }
    }
};

// Time Complexity : O(k) + O(n - k) + O(n), which simplifies to O(n).
// Space Complexity : O(1);


class Solution{
    void reverse(int nums[],int start,int end){
        
    while(start < end){
    nums[start] = nums[start] + nums[end];
    nums[end] = nums[start] - nums[end];
    nums[start] = nums[start] - nums[end];
    start++;
    end--;
    }
    }
    
    public:

    void rotateArr(int arr[], int d, int n){
    d = d % n;
    reverse(arr,0,d-1);
    reverse(arr,d,n-1);
    reverse(arr,0,n-1);
    }
};