class Solution {
public:
    int bitwiseComplement(int n) {
        if(n==0) return 1;
        int counter = 0;
        int result = 0;
        while(n){
            int r = n % 2;
            result += pow(2,counter) * !r;
            n /= 2;
            counter++;
        }
        return result;
    }
};

class Solution {
public:
    int bitwiseComplement(int n) {
        int mask = 1;
        while(mask < n){
            mask = (mask << 1) | 1;
        }
        return n ^ mask; // 1 xor 1 = 0 and 0 xor 1 = 1
    }
};