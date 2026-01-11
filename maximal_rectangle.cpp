#include <bits/stdc++.h>
class Solution
{
public:
    int maximalRectangle(vector<vector<char>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        int maxiarea = 0;
        vector<vector<int>> presum(n, vector<int>(m, 0));

        for (int j = 0; j < m; j++)
        {
            int sum = 0;
            for (int i = 0; i < n; i++)
            {
                if (matrix[i][j] == '1')
                {
                    sum += 1;
                }
                else
                {
                    sum = 0;
                }
                presum[i][j] = sum;
            }
        }

        for (int i = 0; i < n; i++)
        {
            maxiarea = max(maxiarea, largestRectangleArea(presum[i]));
        }

        return maxiarea;
    }

    int largestRectangleArea(vector<int> &heights)
    {
        int n = heights.size();
        stack<int> st;
        int maxArea = 0;
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && heights[st.top()] > heights[i])
            {
                int element = st.top();
                st.pop();
                int NSE = i;
                int PSE = st.empty() ? -1 : st.top();
                maxArea = max(maxArea, (NSE - PSE - 1) * heights[element]);
            }
            st.push(i);
        }
        while (!st.empty())
        {
            int NSE = n;
            int element = st.top();
            st.pop();
            int PSE = st.empty() ? -1 : st.top();
            maxArea = max(maxArea, (NSE - PSE - 1) * heights[element]);
        }
        return maxArea;
    }
};