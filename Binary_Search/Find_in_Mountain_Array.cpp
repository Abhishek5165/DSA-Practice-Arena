// Time complexit : O(2*logn);
// Space complexit : O(1);

class Solution {
public:
    int findPeak(MountainArray& mountainArr) {

        int n = mountainArr.length();
        int Left = 0;
        int Right = n - 1;

        while (Left < Right) {
            int mid = Left + (Right - Left) / 2;

            if (mountainArr.get(mid) < mountainArr.get(mid + 1)) {
                Left = mid + 1;
            } 
            else {
                Right = mid;
            }
        }
        return Left;
    }

    int solve1(MountainArray& mountainArr, int Left, int Right,
    int target) {

        while (Left <= Right) {
            int mid = Left + (Right - Left) / 2;

            if (mountainArr.get(mid) == target) {
                return mid;
            } 
            else if (mountainArr.get(mid) > target) {
                Right = mid - 1;
            } 
            else {
                Left = mid + 1;
            }
        }
        return -1;
    }

    int solve2(MountainArray& mountainArr, int Left, int Right,
    int target) {

        while (Left <= Right) {

            int mid = Left + (Right - Left) / 2;

            if (mountainArr.get(mid) == target) {
                return mid;
            } 
            else if (mountainArr.get(mid) > target) {
                Left = mid + 1;
            } 
            else {
                Right = mid - 1;
            }
        }
        return -1;
    }

    int findInMountainArray(int target, MountainArray& mountainArr) {

        int n = mountainArr.length();
        int index = findPeak(mountainArr);

        int ans = solve1(mountainArr, 0, index, target);

        if (ans != -1) {
            return ans;
        }
        ans = solve2(mountainArr, index + 1, n - 1, target);
        return ans;
    }
};