// Time Complexity : O(logn);
// Space Complexity : O(logn);

class MyCalendar {
public: 
    set<pair<int,int>>st;
    MyCalendar() {
        
    }
    bool book(int start, int end) {
    auto it = st.lower_bound({start,end});
    
    // check if the current event overlap the next event ...
    if(it != st.end() && it->first < end){
    return false;
    }
     // check if the current event overlap the prev event ...
    if(it != st.begin()){
    auto prevIt = prev(it);
    if(start < prevIt->second){
    return false;
    }
    }
    st.insert({start,end});
    return true;
    }
};
