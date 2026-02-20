class Solution {
public:
    string solve(string s){
        vector<string> specials; // storing the special substrings

        int start = 0;
        int sum = 0;

        for(int i = 0; i < s.length();i++){
            sum += s[i] == '1' ? 1 : -1;

            if(sum==0){ // special substring found
                string inner = s.substr(start+1,i-start-1); // finding the substring 
                specials.push_back("1" + solve(inner) + "0"); // "1------0" property of special substring
                start = i+1; // for the next special substring
            }
        }

        sort(specials.begin(),specials.end(),greater<string>()); // sorting in descending order

        string result = "";
        for(auto &it : specials){
            result += it;
        }
        return result;
    }

    string makeLargestSpecial(string s) {
        return solve(s);
    }
};