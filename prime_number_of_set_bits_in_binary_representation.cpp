class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        unordered_set<int>st{2,3,5,7,11,13,17,19,23,29,31};
        int count = 0;
        for(int i = left; i <=right;i++){
            int setBits = __builtin_popcount(i);
            if(st.find(setBits) != st.end()){
                count++;
            }
        }
        return count;
    }
};