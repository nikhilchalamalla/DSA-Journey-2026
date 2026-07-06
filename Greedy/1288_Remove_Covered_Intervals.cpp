/*
Problem: 1288. Remove Covered Intervals

Platform: LeetCode

Difficulty: Medium

Topics:
* Array
* Sorting
* Greedy

Problem Statement:
Given an array intervals where intervals[i] = [li, ri]
represents the interval [li, ri).

Remove all intervals that are completely covered by another
interval in the list.

An interval [a, b) is covered by [c, d) if and only if:

c <= a
and
b <= d

Return the number of remaining intervals.

Example:

Input:
intervals = [[1,4],[3,6],[2,8]]

Output:
2

Explanation:
Interval [3,6] is completely covered by [2,8],
so it is removed.

Approach:
1. Sort intervals by:
   - Starting point in ascending order.
   - If starting points are equal, ending point in descending order.
2. Traverse the sorted intervals while keeping track of the
   maximum ending point seen so far.
3. If the current interval ends after maxEnd,
   it is not covered:
   - Count it.
   - Update maxEnd.
4. Otherwise, it is completely covered by a previous interval
   and can be ignored.

Time Complexity: O(n log n)

Space Complexity: O(1)

Where:
n = Number of intervals
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int removeCoveredIntervals(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end(),
             [](const vector<int> &a, const vector<int> &b)
             {
                 if (a[0] == b[0])
                     return a[1] > b[1];

                 return a[0] < b[0];
             });

        int maxEnd = -1;
        int remaining = 0;

        for (const auto &interval : intervals)
        {
            if (interval[1] > maxEnd)
            {
                remaining++;
                maxEnd = interval[1];
            }
        }

        return remaining;
    }
};