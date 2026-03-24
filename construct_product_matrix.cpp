class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int mod = 12345;
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>>prefix(n,vector<int>(m,0));
        vector<vector<int>>suffix(n,vector<int>(m,0));
        vector<vector<int>>result(n,vector<int>(m,0));

        //prefix traversal
        long long pre = 1;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                prefix[i][j] = (int)pre;
                pre = (pre * grid[i][j]) % mod;
            }
        }
        //suffix traversal
        long long suff = 1;
        for(int i = n-1; i >= 0; i--){
            for(int j = m-1; j >= 0; j--){
                suffix[i][j] = (int)suff;
                suff = (suff * grid[i][j]) % mod;
            }
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                result[i][j] = (prefix[i][j] * suffix[i][j]) % mod;
            }
        }
        return result;
    }
};