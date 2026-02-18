
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

// method -2 => using binary division
class Solution {
public:
    bool hasAlternatingBits(int n) {
        int prevBit = n % 2;
        n /= 2;
        while(n > 0){
            int currBit = n % 2;
            if(currBit == prevBit){
                return false;
            }
            n /= 2;
            prevBit = currBit;
        }
        return true;
    }
};