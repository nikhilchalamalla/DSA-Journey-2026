/*
Problem: 2144. Minimum Cost of Buying Candies With Discount
Platform: LeetCode
Difficulty: Easy
Date Solved: 01-06-2026

Problem Link:
https://leetcode.com/problems/minimum-cost-of-buying-candies-with-discount/

Approach:
1. Sort the candy costs in descending order.
2. For every group of 3 candies:
   - Pay for the first two most expensive candies.
   - Get the third candy for free.
3. Add only the costs of candies that need to be paid for.

Example:
cost = [6,5,7,9,2,2]

After sorting:
[9,7,6,5,2,2]

Pay: 9 + 7
Free: 6

Pay: 5 + 2
Free: 2

Total Cost = 23

Time Complexity: O(n log n)
Space Complexity: O(1) (excluding sorting space)

*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minimumCost(vector<int> &cost)
    {

        int n = cost.size();

        sort(cost.begin(), cost.end(), greater<int>());

        int total = 0;

        for (int i = 0; i < n; i++)
        {
            if (i % 3 != 2)
            {
                total += cost[i];
            }
        }

        return total;
    }
};