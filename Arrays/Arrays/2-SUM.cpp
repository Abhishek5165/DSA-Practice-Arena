// Time Complexity : O(N*N);
// Space Complexity : O(1);

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

    int n = nums.size();

    for(int i=0;i<n;i++){
    int sum = 0;
    for(int j=i+1;j<n;j++){
    sum = nums[i] + nums[j];
    if(sum == target){
    return {i,j};
    break;
    }
    }
    }   
    return {-1,-1};
    }
};

// Using HashMap ...

// Time Complexity : O(N);
// Note: In the worst case(which rarely happens), the unordered_map takes O(N) to find an element. In that case, the time complexity will be O(N2).

// Space Complexity : O(1);

vector<int> twoSum(int n, vector<int> &arr, int target) {
    unordered_map<int, int> mpp;

    for (int i = 0; i < n; i++) {
        int num = arr[i];
        int moreNeeded = target - num;
        if (mpp.find(moreNeeded) != mpp.end()) {
            return {mpp[moreNeeded], i};
        }
        mpp[num] = i;
    }
    return { -1, -1};
}

// This is optimise approch for two sum if we have to find the indexes...
// Time Complexity: O(N), where N = size of the array.

// In the worst case(which rarely happens), the unordered_map takes O(N) to find an element. In that case, the time complexity will be O(N^N).

// If we use map instead of unordered_map, the time complexity will be O(N* logN) as the map data structure takes logN time to find an element.

// Space Complexity: O(N) as we use the map data structure.


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    int n = nums.size();
    unordered_map<int,int>mpp;
    for(int i=0;i<n;i++){
    int remaining = target - nums[i];

    if(mpp.find(remaining) != mpp.end()){
    return {mpp[remaining],i};
    }
    mpp[nums[i]] = i;
    } 
    return {-1,-1};
    }
};

// But here additional array would be used ..
// Time Complexity : O(N) + O(NLogN);
// Space Complexity : O(N);


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        vector<pair<int,int>>temp;

        for(int i = 0; i < nums.size(); i++){
            pair<int,int> P = {nums[i], i};
            temp.push_back(P);
        }   

        sort (temp.begin(), temp.end());
        int s = 0;
        int e = nums.size()-1;

        while(s < e){
            int sum = temp[s].first + temp[e].first;
            if(sum == target){
                return {temp[s].second,temp[e].second};
                break;
            } 
            if(sum < target){
                s++;
            }
            else {
                e--;
            }
        }
        return {-1,-1};
    }
};