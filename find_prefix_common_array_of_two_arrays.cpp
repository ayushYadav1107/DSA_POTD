class Solution
{
public:
    vector<int> findThePrefixCommonArray(vector<int> &A, vector<int> &B)
    {
        int n = A.size();
        unordered_map<int, int> mpp;
        vector<int> prefix(n);

        if (A[0] == B[0])
        {
            prefix[0] = 1;
        }
        else
        {
            mpp[A[0]]++;
            mpp[B[0]]++;
            prefix[0] = 0;
        }
        for (int i = 1; i < n; i++)
        {
            mpp[A[i]]++;
            mpp[B[i]]++;

            prefix[i] = prefix[i - 1];
            if (A[i] == B[i])
            {
                prefix[i] += 1;
                continue;
            }
            if (mpp[A[i]] == 2)
            {
                prefix[i] += 1;
            }
            if (mpp[B[i]] == 2)
            {
                prefix[i] += 1;
            }
        }
        return prefix;
    }
};