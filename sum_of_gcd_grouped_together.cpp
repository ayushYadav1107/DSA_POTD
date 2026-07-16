class Solution {
public:
    int gcd(int a, int b){
        if(a==0) return b;
        
        return gcd(b % a,a);
    }
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        vector<int>prefixGCD(n);

        int maxEle = INT_MIN;
        for(int i = 0; i < n; i++){
            maxEle = max(maxEle,nums[i]);
            prefixGCD[i] = gcd(nums[i],maxEle);
        }

        sort(prefixGCD.begin(),prefixGCD.end());
        long long sum = 0;
        int l = 0;
        int r = prefixGCD.size() - 1;
        while(l < r){
            sum += gcd(prefixGCD[l],prefixGCD[r]);
            l++;
            r--;
        }

        return sum;
    }
};