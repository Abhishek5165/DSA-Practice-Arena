// Approch -1
// Time complexity : O(n);
// Space complexity : O(n);

class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {

    unordered_map<int,int>mpp;

    for(auto &it:edges){
    int one = it[0];
    int two = it[1];

    mpp[one]++;
    mpp[two]++;
    }
    for(auto &eg : mpp){
    if(eg.second == edges.size()){
    return eg.first;
    }
    }
    return -1;
    }
};

// Approch -2 
// Time complexity : O(1);
// Space complexity : O(1);

class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {

        vector<int> first = edges[0];
        vector<int> second = edges[1];

        if (first[0] == second[0] || first[0] == second[1]) {
            return first[0];
        }
        return first[1];
    }
};