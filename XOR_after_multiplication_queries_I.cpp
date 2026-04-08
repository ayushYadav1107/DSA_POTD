class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int MOD = 1e9 + 7;
        
        for(auto &it : queries){
            int l = it[0];
            int r = it[1];
            int k = it[2];
            int v = it[3];

            int idx = l;
            while(idx <= r){
                nums[idx] = (1LL * nums[idx] * v) % MOD;

                idx += k;
            }
        }
        int XOR = nums[0];
        for(int i = 1; i < nums.size(); i++){
            XOR ^= nums[i];
        }
        return XOR;
    }
};