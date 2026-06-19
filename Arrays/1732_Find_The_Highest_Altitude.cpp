/*
Problem: 1732. Find the Highest Altitude

Platform: LeetCode

Difficulty: Easy

Topics:
- Arrays
- Prefix Sum

Approach:
1. The biker starts at altitude 0.
2. Convert the gain array into a running prefix sum.
3. Each prefix sum represents the altitude at that point.
4. The answer is the maximum altitude encountered.
5. Compare with 0 because the starting altitude is also a valid point.

Time Complexity: O(n)

Space Complexity: O(1)
*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int largestAltitude(vector<int> &gain)
    {
        int n = gain.size();

        for (int i = 1; i < n; i++)
        {
            gain[i] += gain[i - 1];
        }

        return max(0, ranges::max(gain));
    }
};