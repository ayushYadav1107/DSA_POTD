class Solution {
public:
    vector<bool> isPrime;

    void buildSieve(int maxEle){
        isPrime.resize(maxEle+1, true);

        isPrime[0] = false;
        isPrime[1] = false;

        for(int i = 2; i*i <= maxEle;i++){
            if(isPrime[i]){
                for(int j = i*i; j <= maxEle; j+= i){
                    isPrime[j] = false;
                }
            }
        }
    }

    int minJumps(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int,vector<int>>mpp; // element -> indices
        int maxEle = 0;
        for(int i = 0; i < n; i++){
            mpp[nums[i]].push_back(i);
            maxEle = max(maxEle,nums[i]);
        }

        // build isPrime using sieve method 
        buildSieve(maxEle); // O(maxEle * log(log(maxEle)))

        queue<int> q;
        vector<bool>visited(n,false);
        q.push(0);
        visited[0] = true;

        unordered_set<int> seen; // to store prime numbers already visited

        int steps = 0;

        while(!q.empty()){ //(O(n)) -> visited each node exactly once
            int size = q.size();
            while(size--){
                int i = q.front();
                q.pop();

                if(i==n-1){
                    return steps;
                }

                if(i-1 >= 0 && !visited[i-1]){
                    q.push(i-1);
                    visited[i-1] = true;
                } 

                if(i + 1 <= n-1 && !visited[i+1]){
                    q.push(i+1);
                    visited[i+1] = true;
                }

                if(!isPrime[nums[i]] || seen.count(nums[i])){
                    continue;
                }

                for(int multiple = nums[i]; multiple <= maxEle; multiple += nums[i]){
                    if(mpp.find(multiple) == mpp.end()){
                        continue;
                    }

                    for(int &j : mpp[multiple]){
                        if(!visited[j]){
                            q.push(j);
                            visited[j] = true;
                        }
                    }
                }

                seen.insert(nums[i]); // we have processed that prime 
            }
            steps++;
        }
        return steps;
    }
};

// TC -> O(n + maxEle * log(log(maxEle)))
// SC -> 0(n)