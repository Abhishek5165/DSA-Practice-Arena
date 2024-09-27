// Time Complexity : O(n);
// Space Complexity : O(n);

class MyCalendarTwo {
public:
    vector<pair<int,int>>d_booking;
    vector<pair<int,int>>booking;
    bool checkOverLap(int A,int B,int start,int end){
    return (max(A,start) < min(B,end));
    }
    pair<int,int> findOverLap(int A,int B,int start,int end){
    return {max(A,start),min(B,end)};
    }
    MyCalendarTwo() {}
    bool book(int start, int end) {
    
    for(pair<int,int>d : d_booking){
    if(checkOverLap(d.first,d.second,start,end)){
    return false;
    }
    }
    for(pair<int,int>b : booking){
    if(checkOverLap(b.first,b.second,start,end)){
    d_booking.push_back(findOverLap(b.first,b.second,
    start,end));
    }
    }
    booking.push_back({start,end});
    return true;
    }
};