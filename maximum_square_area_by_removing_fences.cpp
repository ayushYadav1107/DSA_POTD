class Solution {
public:
    int M = 1e9 + 7;
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        // adding 1 and m,n to the fences
        hFences.push_back(1);
        hFences.push_back(m);
        vFences.push_back(1);
        vFences.push_back(n);

        sort(hFences.begin(),hFences.end());
        sort(vFences.begin(),vFences.end());

        unordered_set<int>widths;// using set to get rid of duplicates width lengths
        // finding the different widths possible
        for(int i = 0; i < hFences.size(); i++){
            for(int j = i+1; j < hFences.size();j++){
                widths.insert(hFences[j]-hFences[i]);
            }
        }
        int maxSide = 0;
        for(int i = 0; i < vFences.size(); i++){
            for(int j = i+1; j < vFences.size();j++){
                int height = vFences[j]-vFences[i];
                if(widths.find(height) != widths.end()){
                    maxSide = max(maxSide,height);
                }
            }
        }

        return maxSide == 0 ? -1 : (1LL *maxSide * maxSide) % M;
    }
};