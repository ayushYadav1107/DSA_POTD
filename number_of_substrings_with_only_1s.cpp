class Solution
{
public:
    int numSub(string s)
    {
        int MOD = 1e9 + 7;
        int cnt = 0;
        int total = 0;
        for (char &ch : s)
        {
            if (ch == '1')
            {
                cnt++;
            }
            else
            {
                cnt = 0;
            }
            total = (total + cnt) % MOD;
        }
        return total;
    }
};