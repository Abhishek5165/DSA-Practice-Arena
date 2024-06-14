// O(N^2), (where N = size of the array) worst, and average cases.
// Best case - TC -> O(N)

// Space Complexity = O(1)


class Solution {
  public:
    void bubbleSort(int arr[], int n) {
     for(int i=n-1;i>=0;i--){
         
     for(int j=0;j<=i-1;j++){
        
     if(arr[j] > arr[j+1]){
         
     arr[j] = arr[j] + arr[j+1];
     arr[j+1] = arr[j] - arr[j+1];
     arr[j] = arr[j] - arr[j+1];
     }
     }
     }
    }
};

// loops are in the same order


class Solution {
  public:
    void bubbleSort(int arr[], int n) {
    for(int i=0;i<n-1;i++){
        
    for(int j=0;j<n-i-1;j++){
        
    if(arr[j]>arr[j+1]){
        
    swap(arr[j],arr[j+1]);
    }
    }
    }
    }
};


// Does sorting happen in place in Bubble sort?

Yes, Bubble sort performs the swapping of adjacent pairs without the use of any major data structure. Hence Bubble sort algorithm is an in-place algorithm.

// Is the Bubble sort algorithm stable?

Yes, the bubble sort algorithm is stable.



// Recursive bubble sort (Approch - 2)

Time Complexity: O(n*n)
Auxiliary Space: O(n)

// Based on the number of comparisons in each method, the recursive bubble sort is better than the iterative bubble sort, but the time complexity for both the methods is same.

class Solution {
  public:
    void bubbleSort(int arr[], int n) {
    
    if(n == 1) return;   // base case 
    int count = 0;
    for(int i=0;i<n-1;i++){
        
    if(arr[i] > arr[i+1]){
    swap(arr[i],arr[i+1]);
    count++;
    }
    }
    // Check if any recursion happens or not 
    // If any recursion is not happen then return 
    if(count == 0) return;

    bubbleSort(arr,n-1);
    }
};


