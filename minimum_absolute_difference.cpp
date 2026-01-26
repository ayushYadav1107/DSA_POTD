class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>>result;
        int n = arr.size();
        sort(arr.begin(),arr.end());
        
        int minDiff = INT_MAX;

        for(int i = 0; i < n-1; i++){
            int diff = arr[i+1] - arr[i];
            minDiff = min(minDiff,diff);
        }
        // pair<int,int>P;
        for(int i = 1; i <= n-1;i++){
            if(arr[i]-arr[i-1] == minDiff){
                vector<int>pair{arr[i-1],arr[i]};
                result.push_back(pair);
            }
        }
        return result;
    }
};