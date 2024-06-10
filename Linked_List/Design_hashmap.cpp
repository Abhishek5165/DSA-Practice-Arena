// Constant Space but not optimise

// fails when :

// 1. when there is negative keys
// 2. when there is other than integer data type of key
// 3. when size is large

class MyHashMap {
public:
    vector<int>vec;
    int size;
    MyHashMap() {
    size = 1e6+1;
    vec.resize(size);

    fill(begin(vec),end(vec),-1);
    }
    
    void put(int key, int value) {
    vec[key] = value;
    return;
    }
    
    int get(int key) {
    return vec[key];  
    }
    
    void remove(int key) {
    vec[key] = -1;
    }
};


// Approch - 2 using buckets 


class MyHashMap {
public:
    vector<list<pair<int,int>>>bucket;
    int size = 1000;
    MyHashMap() {
    bucket.resize(size); 
    }
    
    void put(int key, int value) {

    int bucket_no = key%size;
    auto &chain = bucket[bucket_no];

    for(auto &it:chain){

    if(key == it.first){
    it.second = value;
    return;
    }
    }
    chain.emplace_back(key,value);    
    }
    
    int get(int key) {
    
    int bucket_no = key%size;
    auto &chain = bucket[bucket_no];

    if(chain.empty()){
    return -1;
    }

    for(auto &it:chain){

    if(it.first == key){
    return it.second;
    }
    }
    return -1;
    }
    
    void remove(int key) {

     int bucket_no = key%size;
    auto &chain = bucket[bucket_no];

    for(auto it=chain.begin();it!=chain.end();it++){

    if(it->first == key){
    chain.erase(it);
    return;
    }
    }   
    }
};
