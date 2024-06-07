// Based on Partitioning we take the last element as Piviot 

TC = Best and Average = O(n log n) worst case main O(n^2)
SC = O(logn)


class Solution
{
    public:
    //Function to sort an array using quick sort algorithm.
    void quickSort(int arr[], int low, int high)
    {
     if(low >= high){
     return;
     }
     int p = partition(arr,low,high);
     
     quickSort(arr,low,p-1);
     quickSort(arr,p+1,high);
    }
    
    public:
    int partition (int arr[], int low, int high)
    {
     int pValue = arr[high];
     int pi = low;
     
     for(int i=low;i<high;i++){
         
     if(arr[i] <= pValue){
     swap(arr[i],arr[pi]);
     pi++;
     }
     }
     swap(arr[pi],arr[high]);
     return pi;
    }
};