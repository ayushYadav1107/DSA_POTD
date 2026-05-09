class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        int layers = (min(m,n))/2;

        for(int layer = 0; layer < layers;layer++){

            vector<int>nums;

            int top = layer;
            int bottom = m-layer-1;
            int left = layer;
            int right = n-layer-1;

            //top row -> left to right
            for(int j = left; j <= right;j++){
                nums.push_back(grid[top][j]);
            }
            // rightmost column -> top+1 to bottom-1
            for(int i = top+1; i <= bottom-1;i++){
                nums.push_back(grid[i][right]);
            }
            // bottom row -> right to left
            for(int j = right; j >= left; j--){
                nums.push_back(grid[bottom][j]);
            }
            // left column -> bottom - 1 to top + 1;
            for(int i = bottom-1; i >= top+1; i--){
                nums.push_back(grid[i][left]);
            }

            int size = nums.size();
            int new_k = k % size;
            rotate(begin(nums),begin(nums)+ new_k,end(nums));

            int idx = 0;
            
            for(int j = left; j <= right; j++){
                grid[top][j] = nums[idx++];
            }

            for(int i = top+1; i <= bottom-1; i++){
                grid[i][right] = nums[idx++];
            }

            for(int j = right; j >= left; j--){
                grid[bottom][j] = nums[idx++];
            }

            for(int i = bottom-1; i >= top+1; i--){
                grid[i][left] = nums[idx++];
            }
        }
        return grid;
    }
};

//T.C -> O(M*N)
//S.C -> O(M+N)