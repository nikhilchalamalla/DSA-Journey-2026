/*
Problem: 3336. Find the Number of Subsequences With Equal GCD

Platform: LeetCode

Difficulty: Hard

Topics:
* Dynamic Programming
* Math
* GCD
* Memoization

Problem Statement:
You are given an integer array nums.

Your task is to find the number of pairs of non-empty subsequences
(seq1, seq2) such that:

1. seq1 and seq2 are disjoint.
2. The GCD of seq1 is equal to the GCD of seq2.

Return the total number of such pairs.

Since the answer can be very large, return it modulo 10^9 + 7.

Example 1:
Input:
nums = [1,2,3,4]

Output:
10

Explanation:
There are 10 pairs of disjoint subsequences whose GCD values are equal.

Example 2:
Input:
nums = [10,20,30]

Output:
2

Explanation:
There are 2 valid pairs having GCD equal to 10.

Example 3:
Input:
nums = [1,1,1,1]

Output:
50

Explanation:
Every non-empty subsequence has GCD = 1, producing 50 valid pairs.

Approach:
1. Use Dynamic Programming to keep track of possible GCD values
   for two subsequences.
2. Let dp[g1][g2] represent the number of ways where:
      - First subsequence has GCD = g1.
      - Second subsequence has GCD = g2.
3. Initially, both subsequences are empty.
4. For every number in nums, there are three choices:
      • Ignore the number.
      • Add it to the first subsequence.
      • Add it to the second subsequence.
5. Whenever a number is added, update the corresponding GCD.
6. After processing every number, sum all states where
   g1 == g2 and g1 > 0.
7. Return the answer modulo 1e9 + 7.

Time Complexity: O(n × M²)

Space Complexity: O(M²)

Where:
n = Number of elements in nums
M = Maximum value in nums (200)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int subsequencePairCount(vector<int> &nums)
    {
        const int MOD = 1000000007;
        const int MAX = 200;

        vector<vector<int>> dp(MAX + 1, vector<int>(MAX + 1, 0));
        dp[0][0] = 1;

        for (int x : nums)
        {
            vector<vector<int>> ndp(MAX + 1, vector<int>(MAX + 1, 0));

            for (int g1 = 0; g1 <= MAX; g1++)
            {
                for (int g2 = 0; g2 <= MAX; g2++)
                {
                    if (dp[g1][g2] == 0)
                        continue;

                    long long ways = dp[g1][g2];

                    // Ignore current element
                    ndp[g1][g2] = (ndp[g1][g2] + ways) % MOD;

                    // Add to first subsequence
                    int ng1 = (g1 == 0) ? x : gcd(g1, x);
                    ndp[ng1][g2] = (ndp[ng1][g2] + ways) % MOD;

                    // Add to second subsequence
                    int ng2 = (g2 == 0) ? x : gcd(g2, x);
                    ndp[g1][ng2] = (ndp[g1][ng2] + ways) % MOD;
                }
            }

            dp = move(ndp);
        }

        long long ans = 0;

        for (int g = 1; g <= MAX; g++)
        {
            ans = (ans + dp[g][g]) % MOD;
        }

        return (int)ans;
    }
};