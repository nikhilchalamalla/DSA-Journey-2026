/*
Problem: 1833. Maximum Ice Cream Bars

Platform: LeetCode

Difficulty: Medium

Topics:
- Greedy
- Counting Sort

Approach:
1. Count the frequency of each ice cream cost using a frequency array.
2. Traverse costs from smallest to largest.
3. Buy as many ice creams as possible for each cost.
4. Reduce the available coins accordingly.
5. Count the total number of ice creams purchased.
6. Return the maximum count.

Time Complexity: O(n + M)
Where:
n = number of ice creams
M = maximum cost value (100000)

Space Complexity: O(M)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxIceCream(vector<int> &costs, int coins)
    {
        const int MAX_COST = 100000;
        vector<int> freq(MAX_COST + 1, 0);

        int maxCost = 0;

        for (int cost : costs)
        {
            freq[cost]++;
            maxCost = max(maxCost, cost);
        }

        int count = 0;

        for (int cost = 1; cost <= maxCost; cost++)
        {
            if (freq[cost] == 0)
                continue;

            int canBuy = min(freq[cost], coins / cost);

            count += canBuy;
            coins -= canBuy * cost;

            if (coins == 0)
                break;
        }

        return count;
    }
};