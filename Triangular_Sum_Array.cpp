class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int size = nums.size();
        while(size != 1){
            for(int i = 0; i < size-1;i++){
                nums[i] = (nums[i] + nums[i+1]) % 10;
            }
            size--;
        }
        return nums[0];
    }
};