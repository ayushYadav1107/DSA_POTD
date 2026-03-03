class Solution {
public:
    string invert(string s){
        for(char &c : s){
            c = (c== '0') ? '1' : '0';
        }
        return s;
    }
    string solve(int n, string s){
        if(n==1){
            return s;
        }
        string inverted_s = invert(s);
        reverse(inverted_s.begin(),inverted_s.end());

        string new_s = s + "1" + inverted_s;
        return solve(n-1,new_s); 
    }
    char findKthBit(int n, int k) {
        string ans = solve(n,"0");
        char ans_bit = ans[k-1];
        return ans_bit;
    }
};