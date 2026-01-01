class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1; // maintain carry
        for (int i = digits.size() - 1; i >= 0; i--) {
            int sum = digits[i] + carry;
            digits[i] = sum % 10; // if digit is 9 then 0 will be appended here
            carry = sum / 10; // carry will be 0 if digit was not 9 
        }
        if (carry) {
            digits.insert(digits.begin(), 1); // {1,.....}
        }
        return digits;
    }
};