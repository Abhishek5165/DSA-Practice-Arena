// Time Complexity : O(1) for all operations.
// Space Complexity : O(K);

class MyCircularDeque {
vector<int>dequeue;
int front;
int rare;
int count;
int K;

public:
    MyCircularDeque(int k) {
    dequeue = vector<int>(k);
    front = 0;
    rare = k-1;
    K = k;
    count = 0;
    }
    
    bool insertFront(int value) {
    if(isFull()){
    return false;
    } 
    front = (front-1+K)%K;
    dequeue[front] = value;
    count++;
    return true;
    }
    
    bool insertLast(int value) {
    if(isFull()){
    return false;
    } 
    rare = (rare+1)%K;
    dequeue[rare] = value;
    count++;
    return true;
    }
    
    bool deleteFront() {
    if(isEmpty()){
    return false;
    }
    front = (front+1)%K;
    count--;
    return true;
    }
    
    bool deleteLast() {
    if(isEmpty()){
    return false;
    }
    rare = (rare-1+K)%K;
    count--;
    return true;
    }
    
    int getFront() {
    if(isEmpty()){
    return -1;
    }    
    return dequeue[front];
    }
    
    int getRear() {
    if(isEmpty()){
    return -1;
    }    
    return dequeue[rare];
    }
    
    bool isEmpty() {
    return (count == 0);  
    }
    bool isFull() {
    return (count == K);
    }
};
