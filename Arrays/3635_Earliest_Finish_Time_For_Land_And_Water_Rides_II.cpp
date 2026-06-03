/*
Problem: 3635. Earliest Finish Time for Land and Water Rides II

Platform: LeetCode

Difficulty: Medium

Topics:
- Arrays
- Binary Search
- Prefix Minimum

Approach:
1. Precompute the minimum finishing time for rides in one category.
2. Use optimized searching to determine the earliest possible finish time in the other category.
3. Evaluate both ride orders:
   - Land -> Water
   - Water -> Land
4. Return the minimum finish time.

Time Complexity: O((n + m) log(n + m))

Space Complexity: O(n + m)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    static inline int MAX = 300005;

public:
    int earliestFinishTime(vector<int> &la, vector<int> &lb, vector<int> &wa, vector<int> &wb)
    {
        int l = MAX, w = MAX, minL = MAX, minW = MAX;
        int n = la.size(), m = wa.size();

        for (int i = 0; i < n; i++)
            l = min(l, la[i] + lb[i]);

        for (int i = 0; i < m; i++)
        {
            w = min(w, wa[i] + wb[i]);
            minL = min(minL, max(wa[i], l) + wb[i]);
        }

        for (int i = 0; i < n; i++)
            minW = min(minW, max(la[i], w) + lb[i]);

        return min(minW, minL);
    }
};