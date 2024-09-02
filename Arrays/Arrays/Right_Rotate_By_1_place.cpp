// Time Complexity : O(N);
// Space Complexity : O(1);

// arr.insert(arr.begin(), num); involves shifting all elements of the array to the right by one position, which takes O(n) time.

class Solution {
  public:
    void rotate(vector<int> &arr) {
    int n = arr.size();
    int num = arr[n-1];
    arr.insert(arr.begin(),num);
    arr.pop_back();
    }
};
