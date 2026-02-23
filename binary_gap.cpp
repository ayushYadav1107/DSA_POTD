class Solution {
public:
    int binaryGap(int n) {
        bitset<32>b(n);

        int i = 0;
        int firstBit;
        while(i < 32){
            if(b[i]==1){
                firstBit = i; // first set bit
                break;
            }
            i++;
        }
        int maxDistance = INT_MIN;
        for(int i = firstBit+1; i < 32; i++){
            if(b[i]==0){
                continue;
            }else{
                maxDistance = max(maxDistance,i-firstBit);
                firstBit = i;
            }
        } 
        return maxDistance;
    }
};

// method -2 TC => O(logn)
class Solution {
public:
    int binaryGap(int n) {
        int curr = 0;
        int prev = -1;

        int result = 0;

        while(n > 0){
            if((n&1)>0){
                result = (prev != -1) ? max(result,curr-prev): result;
                prev = curr;
            }
            curr++;
            n >>= 1;
        }
        return result;
    }
};

//method-3 using for Loop
class Solution {
public:
    int binaryGap(int n) {
        int prev = -1;

        int result = 0;

        for(int curr = 0; curr < 32; curr++){
            if(((n >> curr)&1) == 1){
                result = (prev != -1) ? max(result,curr-prev): result;
                prev = curr;
            }
        }
        return result;
    }
};