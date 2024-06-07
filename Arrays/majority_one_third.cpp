// Approch - 1 : using Map

// Time Complexity: O(N*logN) + O(N)
// Space Complexity: O(N)

class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {

        int n = nums.size();

        vector<int> ans;

        unordered_map<int, int> mpp;
        for (auto it : nums)
        {
            mpp[it]++;
        }
        for (auto i : mpp)
        {

            if (i.second > n / 3)
            {

                ans.push_back(i.first);
            }
        }
        return ans;
    }
};

// Approch - 2

// Boyer-Moore Majority Voting Algorithm:

// Time Complexity: O(N) + O(N)
// Space Complexity : O(1)

// Since we are required to return elements that appeared more than ⌊n/3⌋ times then we have atmost two elements that we can return.💪

// But how two elements ???🤯🤯🤯🤯
// Since we want to return elements that appeared more than ⌊n/3⌋ times then atleast it must have appeared ⌊n/3⌋ + 1 times.
// ⌊n/3⌋ + 1 is greater than the third of the array so

// `⌊n/3⌋ + 1` * 3 > array size
// So, it is impossible to return more than two elements.😔

class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {

        int count1 = 0, count2 = 0;
        int element1 = 0, element2 = 0;

        for (int i = 0; i < nums.size(); i++)
        {

            if (count1 == 0 && nums[i] != element2)
            {
                count1 = 1;
                element1 = nums[i];
            }

            else if (count2 == 0 && nums[i] != element1)
            {
                count2 = 1;
                element2 = nums[i];
            }
            else if (element1 == nums[i])
            {
                count1++;
            }
            else if (element2 == nums[i])
            {
                count2++;
            }
            else
            {
                count1--;
                count2--;
            }
        }
        count1 = 0, count2 = 0;
        vector<int> ans;
        int threshold = nums.size() / 3;

        for (int i = 0; i < nums.size(); i++)
        {

            if (element1 == nums[i])
            {
                count1++;
            }
            else if (element2 == nums[i])
            {
                count2++;
            }
        }

        if (count1 > threshold)
        {
            ans.push_back(element1);
        }
        if (count2 > threshold)
        {
            ans.push_back(element2);
        }
        return ans;
    }
};