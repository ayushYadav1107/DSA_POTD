class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        unordered_set<int>st;
        int evenCount;
        int oddCount;
        for(int i = 0; i < n; i++){
            st.clear();
            evenCount = oddCount = 0;
            for(int j = i; j < n; j++){
                if((nums[j] & 1)==1){
                    if(st.find(nums[j])==st.end()){
                        oddCount++;
                        st.insert(nums[j]);
                    }
                }else{
                    if(st.find(nums[j])==st.end()){
                        evenCount++;
                        st.insert(nums[j]);
                    }
                }

                if(evenCount==oddCount){
                    ans = max(ans,j-i+1);
                }
            }
        }
        return ans;
    }
};