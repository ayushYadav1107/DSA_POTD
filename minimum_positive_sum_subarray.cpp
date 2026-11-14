class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();
        int best = INT_MAX;

        for (int len = l; len <= r; len++) {
            int i = 0;
            int sum = 0;
            for (int j = 0; j < n; j++) {
                int size = j - i + 1;
                sum += nums[j];
                if (size > len){
                    sum -= nums[i++];
                    size--;
                }
                if (size == len && sum > 0 && sum < best) best = sum;
            }
        }

        return best == INT_MAX ? -1 : best;
    }
};