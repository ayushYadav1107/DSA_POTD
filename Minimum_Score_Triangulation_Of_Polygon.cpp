class Solution {
public:
    int dp[51][51];
    int solve(vector<int>&values,int i,int j){

        if( j-i  + 1 < 3){ // minimum 3 points required for triangle 
            return 0;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int score = INT_MAX;

        for(int k = i+1; k < j;++k){
            int weight = values[i] * values[j] * values[k] + solve(values,i,k) + solve(values,k,j);

            score = min(score,weight);

        }
        return dp[i][j] = score;
    }
    int minScoreTriangulation(vector<int>& values) {
        memset(dp,-1, sizeof(dp));

        int n = values.size();

        return solve(values,0,n-1);
    }
};