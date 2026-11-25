#define ll long long
class Solution {
public:
    int MOD = 1e9 + 7;
    int n;
    //binary exponentiation
    ll findPower(ll a, ll base){
        if(base == 0){
            return 1;
        }

        ll half = findPower(a, base / 2);
        ll result = (half * half) % MOD;
        if(base % 2 == 1){
            result = (result * a) % MOD;
        }

        return result;
    }
    bool check(vector<int>& nums,int mid,int base){
        unordered_map<ll,int>mpp; // {hash , count}

        ll hash = 0;
        ll P = findPower(base,mid-1);

        int i = 0;
        for(int j = 0; j < nums.size(); j++){
            hash = ((hash * base) + nums[j]) % MOD;

            if(j - i + 1 == mid){
                mpp[hash]++;
                hash = (hash - (nums[i] * P) % MOD + MOD) % MOD; // removing the leftmost digit
                i++;
            }
        }

        //checking if we have any hash value in the map with frequency 1
        for(auto &it : mpp){
            if(it.second == 1){
                return true;
            }
        }
        return false;
    }
    int smallestUniqueSubarray(vector<int>& nums) {
        n = nums.size();
        int base = *max_element(nums.begin(),nums.end()) + 1; // taking the base for rolling hash

        int l = 1;
        int r = n;
        int result = n;

        while( l <= r){
            int mid = l + ( r - l) / 2;

            if(check(nums,mid,base)){
                result = mid;
                r = mid - 1; // we need to find the minimum
            }else{
                l = mid + 1;
            }
        }

        return result;
    }
};