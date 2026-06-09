/*
Problem: 3689. Maximum Total Subarray Value I

Platform: LeetCode

Difficulty: Medium

Topics:
- Arrays
- Greedy
- Math

Approach:
1. The maximum possible subarray value is:
   max(nums) - min(nums)
2. Since the same subarray can be chosen multiple times,
   choose the subarray containing both global maximum
   and global minimum exactly k times.
3. Multiply the maximum value by k.

Time Complexity: O(n)

Space Complexity: O(1)
*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long maxTotalValue(vector<int> &nums, int k)
    {
        return (*max_element(nums.begin(), nums.end()) - *min_element(nums.begin(), nums.end())) * 1LL * k;
    }
};