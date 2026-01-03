class Solution {
public:
    int MOD = 1e9 + 7;
    string states[12] = {"RGR","RYR","RGY","RYG","GYG","GRG","GYR","GRY","YRY","YGY","YGR","YRG"};

    int solve(int n, int prev,vector<vector<int>>&dp){
        if(n==0) return 1; // found 1 configuration

        if(dp[n][prev] != -1) return dp[n][prev];

        int result = 0;
        string lastPattern = states[prev];

        for(int curr = 0; curr < 12; curr++){

            if(curr == prev) continue;

            string currPattern = states[curr];
            bool conflict = false;

            for(int col = 0; col < 3; col++){
                if(currPattern[col] == lastPattern[col]){
                    conflict = true;
                    break;
                }
            }

            if(!conflict){
                result = (result + solve(n-1,curr,dp)) % MOD;
            }
        }
        return dp[n][prev] = result;
    }
    int numOfWays(int n) {
        vector<vector<int>> dp(n,vector<int>(12,-1));
        int result = 0;
        for(int i = 0; i < 12; i++){
            result = (result + solve(n-1,i,dp)) % MOD;
        }
        return result;
    }

    //TC : O(n)
    //SC : O(n)
};