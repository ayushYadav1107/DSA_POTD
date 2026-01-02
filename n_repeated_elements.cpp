class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n = nums.size() / 2;
        sort(nums.begin(),nums.end());
        int count = 1;
        int ele = nums[0];
        for(int i = 1; i < nums.size();i++){
            if(nums[i]==ele){
                count++;
                if(count==n){
                    break;
                }
            }else{
                count--;
                if(count==0){
                    ele = nums[i];
                    count = 1;
                }
            }
        }
        return ele;
    }
};