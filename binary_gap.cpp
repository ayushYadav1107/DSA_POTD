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
        for(int i = firstBit; i < 32; i++){
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