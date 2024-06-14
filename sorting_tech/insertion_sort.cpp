
// Time complexity: O(N*N), (where N = size of the array), for the worst, and average cases.
//  time complexity in the best case will boil down to O(N) - already sorted

// Space Complexity: O(1)

class Solution
{
public:
    void insertionSort(int arr[], int n)
    {
        for (int i = 0; i <= n - 1; i++)
        {

            int j = i;
            while (j > 0 && arr[j] < arr[j - 1])
            {

                arr[j] = arr[j] + arr[j - 1];
                arr[j - 1] = arr[j] - arr[j - 1];
                arr[j] = arr[j] - arr[j - 1];
                j--;
            }
        }
    }
};

// using Recursion - (Approch - 2)
// Time Complexity: O(N*N), (where N = size of the array), for the worst, and average cases.

// Space Complexity: O(N) auxiliary stack space.

class Solution
{
    public:
    void insert(int arr[], int i,int n)
    {
     if(i==n){
     return;
     }
     int j = i;
     while(j > 0 && arr[j-1] > arr[j]){
     
     arr[j] = arr[j] + arr[j-1];
     arr[j-1] = arr[j] - arr[j-1];
     arr[j] = arr[j] - arr[j-1];
     j--;
     }
     insert(arr,i+1,n);
    }
     public:
    void insertionSort(int arr[], int n)
    {
     insert(arr,0,n);
    }
};

