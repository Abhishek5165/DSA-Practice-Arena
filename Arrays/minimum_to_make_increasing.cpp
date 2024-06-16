// time Complexity : O(n)
// space Complexity : O(1)

class Solution
{
public:
    int minOperations(vector<int> &nums)
    {

        int n = nums.size();
        int count = 0;
        for (int i = 1; i < n; i++)
        {
            if (nums[i] <= nums[i - 1])
            {
                count += nums[i - 1] - nums[i] + 1;
                nums[i] += nums[i - 1] - nums[i] + 1;
            }
        }
        return count;
    }
};