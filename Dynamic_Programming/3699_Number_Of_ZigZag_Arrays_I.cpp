/*
Problem: 3699. Number of ZigZag Arrays I

Platform: LeetCode

Difficulty: Hard

Topics:

* Dynamic Programming
* Prefix Sum
* Combinatorics

Approach:

1. Let m = r - l + 1 be the number of available values.
2. A valid ZigZag array:

   * Uses values only from [l, r]
   * No two adjacent elements are equal
   * No three consecutive elements are strictly increasing
   * No three consecutive elements are strictly decreasing
3. Use Dynamic Programming where:

   * dp[i][j] represents the number of valid ways ending with value rank j.
4. Instead of checking all previous states directly,
   use cumulative sums to optimize transitions.
5. Alternate between two DP rows to save memory.
6. After processing all positions, sum all valid states.
7. Multiply by 2 to account for both increasing and decreasing directions.

Time Complexity: O(n × m)

Space Complexity: O(m)

Where:
n = length of array
m = r - l + 1
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    static const int MOD = 1000000007;

public:
    static uint32_t dp[2][2000];

    static uint32_t addMod(uint32_t a, uint32_t b)
    {
        a += b;
        if (a >= MOD)
            a -= MOD;
        return a;
    }

    int zigZagArrays(int n, int l, int r)
    {
        int m = r - l + 1;

        bool cur = 0;

        iota(dp[cur], dp[cur] + m, 0u);

        for (int i = 2; i < n; i++)
        {
            cur = !cur;

            uint32_t prefix = 0;

            for (int j = 0, k = m - 1; j < m; j++, k--)
            {
                dp[cur][j] = prefix;
                prefix = addMod(prefix, dp[!cur][k]);
            }
        }

        uint32_t ans = 0;

        for (int j = 0; j < m; j++)
            ans = addMod(ans, dp[cur][j]);

        return (ans * 2LL) % MOD;
    }
};

uint32_t Solution::dp[2][2000];