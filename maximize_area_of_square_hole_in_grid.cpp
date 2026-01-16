class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());

        int maxHBars = 1;
        int maxVBars = 1;

        // longest length of consecutive H bars
        int currMaxHBars = 1;
        for(int i = 0; i < hBars.size()-1;i++){
            if((hBars[i+1] - hBars[i])==1){
                currMaxHBars++;
            }else{
                currMaxHBars = 1;
            }
            maxHBars = max(maxHBars,currMaxHBars);
        } 
        // similarly length of consecutive V bars
        int currMaxVBars = 1;
        for(int i = 0; i < vBars.size()-1;i++){
            if((vBars[i+1] - vBars[i])==1){
                currMaxVBars++;
            }else{
                currMaxVBars = 1;
            }
            maxVBars = max(maxVBars,currMaxVBars);
        }

        // finding the minimum of the two to ensure its a square
        int sqSize = min(maxVBars,maxHBars) + 1;
        return sqSize * sqSize;
    }
};
