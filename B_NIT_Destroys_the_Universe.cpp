#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        int zeroCount = 0;

        for (int i = 0; i < n; i++)
        {
            if (arr[i] == 0)
            {
                zeroCount++;
            }
        }

        bool found_zero = false;
        int left = 0;
        int right = n - 1;

        while (arr[left] == 0)
        {
            left++;
        }
        while (arr[right] == 0)
        {
            right--;
        }

        for (int i = left; i <= right; i++)
        {
            if (arr[i] == 0)
            {
                found_zero = true;
                break;
            }
        }

        if (zeroCount == n)
            cout << 0 << endl;
        else
        {
            if (found_zero)
            {
                cout << 2 << endl;
            }
            else
            {
                cout << 1 << endl;
            }
        }
    }
}