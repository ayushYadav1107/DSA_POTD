class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int n = points.size();        
        int time = 0;
        for(int i = 0; i<n-1;i++){
            int x_point = points[i][0];
            int y_point = points[i][1];

            int B_x_point = points[i+1][0];
            int B_y_point = points[i+1][1];

            time += max(abs(B_x_point-x_point),abs(B_y_point-y_point));
        }
        return time;
    }
};