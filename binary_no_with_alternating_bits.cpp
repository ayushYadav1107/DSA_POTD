
// Method-1) => bitset method
class Solution {
public:
    bool hasAlternatingBits(int n) {
        bitset<32> b(n);
        int highestSetBit = log2(n);

        for(int i = 0; i < highestSetBit;i++){
            if(b[i]==b[i+1]){
                return false;
            }
        }
        return true;
    }
};