// Constant Space but not optimise

// fails when :

// 1. when there is negative keys
// 2. when there is other than integer data type of key
// 3. when size is large

class MyHashSet {
public:
    vector<bool>ans;
    MyHashSet() {
    ans.resize(1000000+10,false);
    }
    
    void add(int key) {
    ans[key] = true;  
    return; 
    }
    
    void remove(int key) {
    ans[key] = false;  
    }
    
    bool contains(int key) {
    return ans[key] == true;   
    }
};


// Approch - 2 using buckets 

class MyHashSet {
public:
    int size;
    vector<list<int>>bucket;

    int getIndex(int key){
    return key % size;
    }
    MyHashSet() {
    size = 15000;
    bucket = vector<list<int>>(size,list<int>{});
    }
    
    void add(int key) {
    
    int index = getIndex(key);
    
    auto it = find(bucket[index].begin(),bucket[index].end(),key);

    if(it == bucket[index].end()){
    bucket[index].push_back(key);
    return;
    }
    }
    
    void remove(int key) {
    
    int index = getIndex(key);
    auto it = find(bucket[index].begin(),bucket[index].end(),key);

    if(it != bucket[index].end()){
    bucket[index].erase(it);
    }
    }
    
    bool contains(int key) {

    int index = getIndex(key);
    auto it = find(bucket[index].begin(),bucket[index].end(),key);

    return it != bucket[index].end();
    }
};
