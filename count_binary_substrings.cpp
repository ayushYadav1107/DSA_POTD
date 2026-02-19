class Solution {
public:
    int countBinarySubstrings(string s) {
        int curr = 1;
        int prev = 0;
        int result = 0;
        for(int i = 1; i < s.length();i++){
            if(s[i]==s[i-1]){
                curr++;
            }else{ // we have curr & prev so take the min out of those two 
                result += min(prev,curr);
                prev = curr;
                curr = 1;
            }
        }
        result += min(prev,curr); // last check when i is out of bounds
        return result;
    }
};