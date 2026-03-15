class Solution {
public:
    vector<char>vec{'a','b','c'};
    void solve(string &curr, vector<string>&result,int n){
        if(curr.length()==n){
            result.push_back(curr); // we got our happy string
            return;
        }

        for(auto &ch : vec){
            if( !curr.empty() && curr.back() == ch) continue;
            curr.push_back(ch); // do
            solve(curr,result,n); // explore
            curr.pop_back(); // undo
        }
    }
    string getHappyString(int n, int k) {
        vector<string>result;
        string curr = "";
        solve(curr,result,n);
        if(k > result.size()) return "";
        return result[k-1];
    }
};

TC : (n * 2^n);
SC : same 

// method -2 optimized :
class Solution {
public:
    vector<char>vec{'a','b','c'};
    void solve(string &curr, string &result,int n,int &count,int &k){
        if(curr.length()==n){
            count++;
            if(count==k){
                result = curr; // we got our happy string
            }
            return;
        }

        for(auto &ch : vec){
            if( !curr.empty() && curr.back() == ch) continue;
            curr.push_back(ch); // do
            solve(curr,result,n,count,k); // explore
            curr.pop_back(); // undo
        }
    }
    string getHappyString(int n, int k) {
        string result = "";
        string curr = "";
        int count = 0;
        solve(curr,result,n,count,k);
        return result;
    }
};

TC : (n * 2^n)
SC : (n) where n is the depth of tree diagram