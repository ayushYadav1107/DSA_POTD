class Solution {
public:
    typedef pair<int,int> P; // freq, ele
    int findTopXSum(unordered_map<int,int> &mpp,int x){
        //min-heap
        priority_queue<P,vector<P>,greater<P>> pq;

        for(auto &it : mpp){
            pq.push({it.second,it.first});

            if(pq.size() > x){
                pq.pop(); // remove smallest element from top
            }
        }

        int sum = 0;
        while(!pq.empty()){
            auto [freq,val] = pq.top();
            pq.pop();

            sum+= freq*val;
        }
        return sum;
    }

    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int i,j;
        int n = nums.size();
        unordered_map<int,int> mpp;
        vector<int> result;
        i = j = 0;

        while(j<n){
            mpp[nums[j]]++;

            if(j - i + 1 == k){
                result.push_back(findTopXSum(mpp,x));

                mpp[nums[i]]--;
                if(mpp[nums[i]]== 0){
                    mpp.erase(nums[i]);
                }
                i++;
            }
            j++;
        }
        return result;
    }
};