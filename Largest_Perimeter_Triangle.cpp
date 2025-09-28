class Solution
{
public:
    // TC => O(nlogn)
    int largestPerimeter(vector<int> &nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        for (int i = n - 3; i >= 0; i--)
        {
            if (nums[i] + nums[i + 1] > nums[i + 2])
            { // a+b > c
                return nums[i] + nums[i + 1] + nums[i + 2];
            }
        }
        return 0;
    }
};