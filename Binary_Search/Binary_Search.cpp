// Time Complexity : O(LogN);
// Space Complexity : O(1);

class Solution{
public:
    int search(vector<int> &nums, int target)
    {
        int N = nums.size();
        int Left = 0;
        int Right = N - 1;

        while (Left <= Right)
        {
            int mid = Left + (Right - Left) / 2;

            if (nums[mid] == target)
            {
                return mid;
                break;
            }
            else if (target > nums[mid])
            {
                Left++;
            }
            else
            {
                Right--;
            }
        }
        return -1;
    }
};