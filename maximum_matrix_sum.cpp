class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        long long sum = 0;
        int negCount = 0;
        int smallestAbsVal = INT_MAX;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                sum += abs(matrix[i][j]);
                if(matrix[i][j] < 0){
                    negCount++;
                }
                smallestAbsVal = min(smallestAbsVal,abs(matrix[i][j])); // smallest value in case of odd no of negatives
            }
        }
        
        if((negCount & 1)){ // no of negatives are odd
            return sum - 2*smallestAbsVal; 
        }else{
            return sum;
        }
    }
};