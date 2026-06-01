// brute force

class Solution {
public:
    static bool custom(int a, int b){
        return a > b;
    }
    int minimumCost(vector<int>& cost) {
        int n = cost.size();
        
        sort(cost.begin(),cost.end(),custom);

        int total_cost = 0;
        for(int i = 0; i <n; i+=3){ 
            for(int j = i; j <= i+1 && j < n;j++){ // skipping the third candy since it is free
                total_cost += cost[j];
            }
        }
        return total_cost;
    }
};