// Time Complexity : O(size * 32 + N * 32);

struct Node {

    Node* Links[2];

    bool containsKey(int bit) { 
        return (Links[bit] != NULL);
    }
    Node* get(int bit) { 
        return Links[bit]; 
    }
    void put(int bit, Node* node) { 
        Links[bit] = node; 
    }
};

class Trie {

    Node* root;

    public:
    Trie() { 
        root = new Node(); 
    }

    // ------------------------------------------

    void insert(int num) {

        Node* node = root;

        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;

            if (!node->containsKey(bit)) {
                node->put(bit, new Node());
            }
            node = node->get(bit);
        }
    }

    // -----------------------------------------------

    int getMax(int num) {
        Node* node = root;
        int numMax = 0;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (node->containsKey(1 - bit)) {
                numMax = numMax | (1 << i);
                node = node->get(1 - bit);
            } 
            else {
                node = node->get(bit);
            }
        }
        return numMax;
    }
};


class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, 
    vector<vector<int>>& queries) {
    Trie T;
    sort(nums.begin(),nums.end());
    vector<pair<int,pair<int,int>>>offlineQueries;
    
    int size = queries.size();
    int n = nums.size();

    for(int i=0;i<size;i++){
    offlineQueries.push_back({queries[i][1],{queries[i][0],i}});
    }
    sort(offlineQueries.begin(),offlineQueries.end());

    int index = 0;
    vector<int>ans(size,0);

    for(int i=0;i<size;i++){
    int mi = offlineQueries[i].first;
    int xi = offlineQueries[i].second.first;
    int ind = offlineQueries[i].second.second;

    while(index < n && nums[index] <= mi){
    T.insert(nums[index]);
    index++;
    }
    if(index == 0){
    ans[ind] = -1;
    }
    else{
    ans[ind] = T.getMax(xi);
    }
    }
    return ans;
    }
};