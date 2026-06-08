class Solution
{
public:
    vector<int> pivotArray(vector<int> &nums, int pivot)
    {
        int n = nums.size();
        vector<int> less;
        vector<int> more;
        int equalCount = 0;

        for (int i = 0; i < n; i++)
        {
            if (nums[i] < pivot)
            {
                less.push_back(nums[i]);
            }
            else if (nums[i] == pivot)
            {
                equalCount++;
            }
            else
            {
                more.push_back(nums[i]);
            }
        }
        int idx = 0;
        for (int i = 0; i < less.size(); i++)
        {
            nums[idx] = less[i];
            idx++;
        }
        for (int i = 0; i < equalCount; i++)
        {
            nums[idx] = pivot;
            idx++;
        }
        for (int i = 0; i < more.size(); i++)
        {
            nums[idx] = more[i];
            idx++;
        }
        return nums;
    }
};