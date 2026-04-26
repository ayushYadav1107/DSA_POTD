class Solution {
public:
    vector<vector<int>>directions{{-1,0},{1,0},{0,1},{0,-1}};
    int m,n;
    bool isCycleDFS(vector<vector<char>>&grid,int i, int j, vector<vector<bool>>&visited,int prev_i,int prev_j){
        visited[i][j] = true;

        for(auto &it : directions){
            int x = it[0];
            int y = it[1];

            int new_i = i + x;
            int new_j = j + y;

            if(new_i < m && new_i >= 0 && new_j < n && new_j >= 0){

                if(grid[new_i][new_j] != grid[i][j])
                    continue;

                if(new_i == prev_i && new_j == prev_j){ // parent
                    continue;
                }

                if(visited[new_i][new_j]){
                    return true;
                }

                if(isCycleDFS(grid,new_i,new_j,visited,i,j)){
                    return true;
                }
            }
        }

        return false;
    }

    bool containsCycle(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();

        vector<vector<bool>>visited(m,vector<bool>(n,false));

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(!visited[i][j] && isCycleDFS(grid,i,j,visited,-1,-1)){
                    return true;
                }
            }
        }
        return false;
    }
};