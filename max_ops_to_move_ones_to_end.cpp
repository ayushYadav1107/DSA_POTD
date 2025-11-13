class Solution
{
public:
    int maxOperations(string s)
    {
        int n = s.size();
        int count1 = 0;
        int operations = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '1')
            {
                count1++;
            }
            else if ((s[i] == '0' && s[i + 1] == '0') && i + 1 < n)
            {
                continue;
            }
            else if (s[i] == '0')
            {
                operations += count1;
            }
        }
        return operations;
    }
};