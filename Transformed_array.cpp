class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);
        for(int i = 0; i <n ; i++){
            if(nums[i]== 0){
                result[i] = nums[i];
            }else if(nums[i] < 0){
                int steps = abs(nums[i]);
                int index = i;
                while(steps > 0){
                    index--;
                    if(index < 0) index = n-1;
                    steps--;
                }
                result[i] = nums[index];
            }else{
                int steps = nums[i];
                int index = i;
                while(steps > 0){
                    index++;
                    if(index == n) index = 0;
                    steps--;
                }
                result[i] = nums[index];
            }
        }
        return result;
    }
};