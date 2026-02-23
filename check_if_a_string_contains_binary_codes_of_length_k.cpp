class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if(k > s.length()) return false;
        unordered_set<string>st;
        int totalCodes = 1 << k;
        for(int i = 0 ; i <= s.length()-k;i++){
            string temp = "";
            for(int j = i; j < i+k; j++){
                temp+= s[j];
            }
            st.insert(temp);
        }
        return st.size() >=totalCodes ? true : false;
    }
};