// Time complexit : O(logn);
// Space complexit : O(1);

class Solution {
public:
    int makeBouquets(vector<int>& bloomDay, int mid, int k) {

        int count = 0;
        int Bouquets = 0;

        for (int i = 0; i < bloomDay.size(); i++) {
            if (bloomDay[i] <= mid) {
                count++;
            } else {
                count = 0;
            }
            if (count == k) {
                Bouquets++;
                count = 0;
            }
        }
        return Bouquets;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {

        int Left = 0;
        int Right = *max_element(begin(bloomDay), end(bloomDay));

        int result = -1;

        while (Left <= Right) {

            int mid = Left + (Right - Left) / 2;
            if (makeBouquets(bloomDay, mid, k) >= m) {
                result = mid;
                Right = mid - 1;
            } 
            else {
                Left = mid + 1;
            }
        }
        return result;
    }
};