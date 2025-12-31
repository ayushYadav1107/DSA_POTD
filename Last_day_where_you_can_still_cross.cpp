
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