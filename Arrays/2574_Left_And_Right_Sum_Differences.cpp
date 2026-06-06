/*
Problem: 2574. Left and Right Sum Differences

Platform: LeetCode

Difficulty: Easy

Topics:
- Arrays
- Prefix Sum

Approach:
1. Calculate the total sum of the array.
2. Maintain:
   - prefix = sum of elements to the left
   - suffix = sum of elements to the right
3. For each index:
   - Update prefix
   - Compute absolute difference between prefix and suffix
4. Store the result.

Time Complexity: O(n)

Space Complexity: O(n)
*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> leftRightDifference(vector<int> &nums)
    {
        int prefix = 0;
        int suffix = accumulate(nums.begin(), nums.end(), 0);

        vector<int> res;

        for (int i : nums)
        {
            prefix += i;
            res.push_back(abs(prefix - suffix));
            suffix -= i;
        }

        return res;
    }
};