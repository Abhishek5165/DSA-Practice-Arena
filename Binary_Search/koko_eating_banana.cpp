// Time Complexity : O(logn);
// Time Complexity : O(1);

class Solution {
public:
    bool posible(vector<int>& piles, int mid, int h) {

        int k = 0;
        for (int i = 0; i < piles.size(); i++) {

            k += piles[i] / mid;
            if (piles[i] % mid != 0) {
                k++;
            }
        }
        return (k <= h);
    }

    int minEatingSpeed(vector<int>& piles, int h) {

        int left = 1;
        int right = *max_element(begin(piles), end(piles));

        while (left < right) {

            int mid = left + (right - left) / 2;

            if (posible(piles, mid, h)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};