class Solution {
public:
    vector<vector<int>> directions = {{1,0},{0,1},{-1,0},{0,-1}};

    bool isPossible(int mid, vector<vector<int>>& grid, int i,int j,vector<vector<bool>>&visited,int n){
        if(i < 0 || i >= n || j < 0 || j>=n || visited[i][j]==true || grid[i][j] > mid){
            return false;
        }
        
        visited[i][j] = true;

        if(i == n-1 && j == n-1){
            return true;
        }

        for(auto &d : directions){
            int x = i + d[0];
            int y = j + d[1];

            if(isPossible(mid,grid,x,y,visited,n)){
                return true;
            }
        }
        return false;
    }

    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();

        int l = grid[0][0];
        int r = 2499; // O( n^2 * log(n^2)) => O( n^2 *  log(n))
        // SC => O(n^2)

        int result = 0;

        while(l<=r){ // binary search on Answers because we need to find minimize the maximum time needed
            int mid = l + (r-l)/2;

            vector<vector<bool>> visited(n,vector<bool>(n,false));

            if(isPossible(mid,grid,0,0,visited,n)){ // bfs or dfs
                result = mid;
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }    
        return result;
    }
};