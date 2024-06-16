// Approch - 1  Brute Force 

The time complexity of the (get) and (put) operations in the provided implementation of an LRU Cache using a vector to store key-value pairs is O(n)

can take linear time in the worst case.

// The space complexity is O(n)

class LRUCache {
public:
    vector<pair<int, int>> cah;
    int n;
    LRUCache(int capacity) { n = capacity; }

    int get(int key) {

        for (int i = 0; i < cah.size(); i++) {

            if (cah[i].first == key) {

                int val = cah[i].second;
                pair<int, int> temp = cah[i];
                cah.erase(cah.begin() + i);
                cah.push_back(temp);

                return val;
            }
        }
        return -1;
    }

    void put(int key, int value) {

        for (int i = 0; i < cah.size(); i++) {

            if (cah[i].first == key) {
                cah.erase(cah.begin() + i);
                cah.push_back({key, value});
                return;
            }
        }
        if (cah.size() == n) {
            cah.erase(cah.begin());
            cah.push_back({key, value});
        } 
        else {
            cah.push_back({key, value});
        }
    }
};

// Approch - 2 Using Linked List 

// Time Complexity : O(1) for both put & get functions
// Space Complexity : O(1)


class LRUCache {
public:
    list<int>dll;
    unordered_map<int,pair<list<int>::iterator,int>>mpp;
    int n;
    LRUCache(int capacity) {
    n = capacity;
    }

    void make_resently_used(int key){

    dll.erase(mpp[key].first);
    dll.push_front(key);
    mpp[key].first = dll.begin();
    }
    
    int get(int key) {

    if(mpp.find(key) == mpp.end()){
    return -1;
    } 
    make_resently_used(key);
    return mpp[key].second;
    }
    
    void put(int key, int value) {

    if(mpp.find(key) != mpp.end()){
    mpp[key].second = value;
    make_resently_used(key);
    }  
    else{

    dll.push_front(key);
    mpp[key] = {dll.begin(),value};
    n--;
    }
    if(n<0){

    int key_to_delete = dll.back();
    mpp.erase(key_to_delete);
    dll.pop_back();
    n++;
    }
    }
};