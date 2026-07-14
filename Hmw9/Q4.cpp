#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        int n = nums.size();
        if (n == 0)
            return {};

        // 1. Determine the maximum power of 2 needed (log2 of n)
        int maxLog = floor(log2(n)) + 1;

        // st[i][j] will store the max of range [i, i + 2^j - 1]
        vector<vector<int>> st(n, vector<int>(maxLog));

        // 2. Base case: ranges of length 2^0 = 1
        for (int i = 0; i < n; i++)
        {
            st[i][0] = nums[i];
        }

        // 3. Precompute the table (Dynamic Programming)
        for (int j = 1; j < maxLog; j++)
        {
            for (int i = 0; i + (1 << j) <= n; i++)
            {
                // Max of range [i, i+2^j-1] is max of two halves of length 2^(j-1)
                st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
            }
        }

        // 4. Precompute logs for O(1) query (optional optimization)
        vector<int> logs(n + 1);
        logs[1] = 0;
        for (int i = 2; i <= n; i++)
        {
            logs[i] = logs[i / 2] + 1;
        }

        // 5. Query for each sliding window
        vector<int> result;
        int p = logs[k]; // largest power of 2 such that 2^p <= k

        for (int i = 0; i <= n - k; i++)
        {
            int L = i;
            int R = i + k - 1;
            // The O(1) magic: compare two overlapping precomputed ranges
            int windowMax = max(st[L][p], st[R - (1 << p) + 1][p]);
            result.push_back(windowMax);
        }

        return result;
    }
};