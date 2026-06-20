/*
Problem: 1840. Maximum Building Height

Platform: LeetCode

Difficulty: Hard

Topics:
- Greedy
- Math
- Sorting

Approach:
1. Add two mandatory restrictions:
   - Building 1 has height 0.
   - Building n can have height at most n - 1.
2. Sort all restrictions by building index.
3. Perform a left-to-right pass:
   - Restrict each building's maximum possible height based on the previous building.
4. Perform a right-to-left pass:
   - Further restrict heights using the next building.
5. For every adjacent pair of restrictions:
   - Compute the maximum possible peak height between them.
6. Return the maximum peak among all segments.

Time Complexity: O(m log m)

Space Complexity: O(m)

Where m = restrictions.size()
*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxBuilding(int n, vector<vector<int>> &restrictions)
    {
        restrictions.push_back({1, 0});
        restrictions.push_back({n, n - 1});

        sort(restrictions.begin(), restrictions.end());

        int m = restrictions.size();

        for (int i = 1; i < m; i++)
        {
            restrictions[i][1] = min(
                restrictions[i][1],
                restrictions[i - 1][1] +
                    (restrictions[i][0] - restrictions[i - 1][0]));
        }

        for (int i = m - 2; i >= 0; i--)
        {
            restrictions[i][1] = min(
                restrictions[i][1],
                restrictions[i + 1][1] +
                    (restrictions[i + 1][0] - restrictions[i][0]));
        }

        int ans = 0;

        for (int i = 0; i < m - 1; i++)
        {
            int x1 = restrictions[i][0];
            int h1 = restrictions[i][1];

            int x2 = restrictions[i + 1][0];
            int h2 = restrictions[i + 1][1];

            int dist = x2 - x1;

            ans = max(ans, (h1 + h2 + dist) / 2);
        }

        return ans;
    }
};