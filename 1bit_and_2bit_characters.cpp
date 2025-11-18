class Solution
{
public:
    bool isOneBitCharacter(vector<int> &bits)
    {
        int n = bits.size();
        if (n == 1)
            return true;
        for (int i = 0; i < n; i++)
        {
            if (bits[i] == 0)
            {
                if (i == n - 1)
                    return true;
                else
                    continue;
            }
            else
            {
                i++;
            }
        }
        return false;
    }
};