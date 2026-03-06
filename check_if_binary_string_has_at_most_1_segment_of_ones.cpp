class Solution {
public:
    bool checkOnesSegment(string s) {
        int length = 0;
        int count = 0;

        for(int i = 0; i < s.length();i++){
            while(s[i]=='1' && i < s.length()){
                length += 1;
                i++;
            }
            if(length >= 1){
                count += 1;
            }
            length = 0;
        }
        if(count == 1){
            return true;
        }
        return false;
    }
};