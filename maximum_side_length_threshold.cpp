class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>>prefix(m,vector<int>(n,0));
        
        //prefix sum subarray prefix[i][j] => sum of all elements from [0,0] to [i,j]
        for(int i = 0; i < m;i++){
            for(int j = 0; j< n; j++){
                prefix[i][j] = (i > 0 ? prefix[i-1][j]: 0) + (j > 0 ? prefix[i][j-1]: 0) - (i > 0 && j > 0 ? prefix[i-1][j-1] : 0) + mat[i][j]; 
            }
        }

        auto sumSquare = [&](int i, int j, int r2,int c2){
            int sum = prefix[r2][c2];
            if(i > 0) sum -= prefix[i-1][c2];
            if(j > 0) sum -= prefix[r2][j-1];
            if(i > 0 && j > 0){
                sum += prefix[i-1][j-1];
            }
            return sum;
        };

        int bestSide = 0;
        for(int i = 0; i<m; i++){
            for(int j = 0; j< n; j++){
                
                for(int k = 0; k < min(m-i,n-j); k++){
                    // second point to make a square in 2D plane
                    int r2 = i+k;
                    int c2 = j+k;

                    int sum = sumSquare(i,j,r2,c2);

                    if(sum <= threshold){
                        bestSide = max(bestSide,k+1);
                    }else{
                        break;
                    }
                } 
            }
        }
        return bestSide;
    }
};