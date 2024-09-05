
// Approch - 1 : using Map 

// Time Complexity: O(N*logN) + O(N), 

// where N = size of the given array.
// Reason: We are using a map data structure. Insertion in the map takes logN time. And we are doing it for N elements. So, it results in the first term         O(N*logN). The second O(N) is for checking which element occurs more than floor(N/2) times. If we use unordered_map instead, the first term will be O(N) for the best and average case and for the worst case, it will be O(N^2).

// Space Complexity: O(N) as we are using a map data structure.

int majorityElement(vector<int> v) {

    //size of the given array:
    int n = v.size();

    //declaring a map:
    map<int, int> mpp;

    //storing the elements with its occurnce:
    for (int i = 0; i < n; i++) {
        mpp[v[i]]++;
    }

    //searching for the majority element:
    for (auto it : mpp) {
        if (it.second > (n / 2)) {
            return it.first;
        }
    }
    return -1;
}

// ----------------------------------------------------------------------

// Optimal Approach:Boyer-Moore Majority Voting Algorithm:

// Time Complexity: O(N) + O(N)
// Space Complexity : O(1)

class Solution {
public:
    int majorityElement(vector<int>& nums) {

    int n = nums.size();
    int count = 0;
    int element = 0;

    for(int i=0;i<n;i++){

    if(count == 0){
    count = 1;
    element = nums[i];
    }
    else if(element == nums[i]){
    count++;
    }
    else{
    count--;
    }
    }
    count = 0;
    for(int i=0;i<n;i++){

    if(nums[i] == element){
    count++;
    }
    }
    if(count > n/2){
    return element;
    }
    return -1;
    }
};




