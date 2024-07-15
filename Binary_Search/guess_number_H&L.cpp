// Time complexity : o(logn);
// Space complexity : o(logn);

class Solution {
public:
    int guessNumber(int n) {

    int left = 0;
    int right = n;

    while(left <= right){

    int mid = left + (right-left)/2;
    int val = guess(mid);

    if(val == 0){
    return mid;
    }
    else if(val == -1){
    right = mid - 1;
    }
    else{
    left = mid + 1;
    }
    }   
    return -1;
    }
};