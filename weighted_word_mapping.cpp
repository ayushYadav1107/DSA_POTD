class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        int n = words.size();
        string result = "";
        for(string word : words){
            int weight = 0;
            for(char ch : word){
                weight += weights[ch - 'a'];
            }
            weight = weight % 26;
            result += 'z' - weight;
        }
        return result;
    }
};