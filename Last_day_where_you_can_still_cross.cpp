
// brute force dfs approach

class Solution {
public:
    int row, col;
    vector<vector<int>>grid;
    vector<vector<bool>>visited;

    bool dfs(int r, int c){
        if(r < 0 || r>= row || c < 0 || c >= col) return false; // all boundary conditions

        if(grid[r][c] == 1 || visited[r][c]) return false;
        
        if(r == row-1) return true;

        visited[r][c] = true;
        return dfs(r+1,c) || dfs(r-1,c) || dfs(r,c+1) || dfs(r,c-1);
    }

    bool canCross(int day, vector<vector<int>>& cells){
        grid.assign(row, vector<int>(col,0)); // initialized a 2D vector with 0 values

        for(int i = 0; i < day; i++){ // assigning the flooded cells
            int r = cells[i][0] - 1;
            int c = cells[i][1] - 1;
            grid[r][c] = 1;
        }

        visited.assign(row, vector<bool>(col,false));

        for(int c = 0; c < col; c++){
            if(grid[0][c] == 0 && !visited[0][c]){
                if(dfs(0,c)){
                    return true;
                }
            }
        }
        return false;
    }

    int latestDayToCross(int r, int c, vector<vector<int>>& cells) {

        row = r;
        col = c;
        
        for(int day = cells.size(); day >=0; day--){
            if(canCross(day,cells)){
                return day;
            }
        }
        return 0;
    }
};


// optimised binary search + dfs approach
class Solution {
public:
    int row, col;
    vector<vector<int>>grid;
    vector<vector<int>>directions{{1,0},{0,1},{-1,0},{0,-1}};

    bool dfs(int r, int c){
        if(r < 0 || r>= row || c < 0 || c >= col) return false;

        if(grid[r][c] == 1) return false;
        
        if(r == row-1) return true;

        grid[r][c] = true;
        
        for(auto &dir : directions){
            int new_r = r + dir[0]; 
            int new_c = c + dir[1];

            if(dfs(new_r,new_c)){
                return true;
            } 
        }
        return false;
    }

    bool canCross(vector<vector<int>>& cells, int mid){
        grid.assign(row, vector<int>(col,0)); // initialized a 2D vector with 0 values

        for(int i = 0; i <= mid; i++){ // assigning the flooded cells
            int r = cells[i][0] - 1;
            int c = cells[i][1] - 1;
            grid[r][c] = 1;
        }


        for(int c = 0; c < col; c++){
            if(grid[0][c] == 0 && dfs(0,c)){
                return true;
            }
        }
        return false;
    }

    int latestDayToCross(int ROW, int COL, vector<vector<int>>& cells) {

        row = ROW;
        col = COL;

        int l = 0; // applying binary search
        int r = cells.size()-1;

        int lastDay = 0;

        while(l <= r){
            int mid = l + (r-l)/2; // overflow condition

            if(canCross(cells,mid)){
                lastDay = mid + 1;
                l = mid + 1;
            }else{
                r = mid - 1;
            }
        }
        
        return lastDay;
    }
};