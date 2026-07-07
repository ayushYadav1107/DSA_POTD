class Solution {
public:
    long long sumAndMultiply(int n) {
        int sum = 0;
        int x = 0;
        while(n){
            int digit = n % 10;
            if(digit){
                x = x * 10 + digit;
                sum += digit;
            }
            n /= 10;
        }
        string str = to_string(x);
        reverse(str.begin(),str.end());
        int x_new = stoi(str);
        return (long long)sum * x_new;
    }
};