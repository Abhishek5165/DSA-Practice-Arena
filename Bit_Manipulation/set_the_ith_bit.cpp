// Time Complexity : O(1);
// Space Complexity : O(1);

class Solution{
public:
    int setKthBit(int N, int K){
        int num = (N | (1 << K));
        return num;
    }
};

