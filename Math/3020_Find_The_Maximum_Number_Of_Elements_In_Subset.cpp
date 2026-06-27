/*
Problem: 3020. Find the Maximum Number of Elements in Subset

Platform: LeetCode

Difficulty: Medium

Topics:

* Hash Map
* Math
* Greedy

Problem Statement:

You are given an array of positive integers nums.

Select a subset of nums that can be arranged in the following form:

[x, x², x⁴, ..., x^(k/2), x^k, x^(k/2), ..., x⁴, x², x]

where k is a non-negative power of 2.

Return the maximum number of elements that can belong to such a subset.

Approach:

1. Count the frequency of every number using a hash map.
2. Handle the special case of value 1 separately:
   - Since 1² = 1, only an odd count of 1's can form a valid chain.
3. For every other distinct value:
   - Start building a chain from the current value.
   - While the current number exists at least twice:
       - Use one occurrence on the left and one on the right.
       - Increase the chain length by 2.
       - Move to its square.
   - If the last squared value exists once, place it in the center.
   - Otherwise, remove one element because a center cannot be formed.
4. Track the maximum valid chain length among all starting values.
5. Return the maximum length.

Time Complexity: O(n)

Space Complexity: O(n)

Where:
n = size of the input array
*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    typedef long long ll;

    int maximumLength(vector<int> &nums)
    {
        unordered_map<ll, ll> mp;

        // Count frequency of each number
        for (auto x : nums)
        {
            mp[x]++;
        }

        ll ans = 1;

        // Special case for number 1
        if (mp.count(1))
        {
            ll cnt = mp[1];

            if (cnt % 2 == 0)
                cnt--;

            ans = max(ans, cnt);
        }

        // Try every number as the starting value
        for (auto [val, freq] : mp)
        {

            if (val == 1)
                continue;

            ll curr = val;
            ll len = 0;

            // Need at least two occurrences to extend the chain
            while (mp.count(curr) && mp[curr] > 1)
            {

                len += 2;

                // Prevent overflow
                if (curr <= 100000)
                    curr *= curr;
                else
                {
                    curr = 0;
                    break;
                }
            }

            // One occurrence can be placed at the center
            if (mp.count(curr) && mp[curr] >= 1)
                len++;
            else
                len--;

            ans = max(ans, len);
        }

        return ans;
    }
};