```cpp
/*
Problem: 3739. Count Subarrays With Majority Element II

Platform: LeetCode

Difficulty: Hard

Topics:
- Prefix Sum
- Hashing
- Balance Technique
- Arrays

Approach:
1. Treat every occurrence of target as +1 and every non-target element as -1.
2. Maintain a running balance while traversing the array.
3. Store the frequency of each balance value.
4. If the current element is the target:
   - Add all previous occurrences of the current balance.
   - Increase the balance.
5. Otherwise:
   - Decrease the balance.
   - Remove invalid contributions.
6. Update the balance frequency.
7. Accumulate the answer for every position.

Time Complexity: O(n)

Space Complexity: O(n)
*/

#include <bits/stdc++.h>
    using namespace std;

constexpr int N = 200002;

long long cntBalance[N];
long long bias;

class Solution
{
public:
    long long countMajoritySubarrays(vector<int> &nums, int target)
    {
        bias = nums.size() + 1;
        int balance = bias;

        memset(cntBalance, 0, (2 * bias) * sizeof(long long));

        cntBalance[balance] = 1;

        long long ans = 0;
        long long sum = 0;

        for (int x : nums)
        {
            if (x == target)
            {
                sum += cntBalance[balance++];
            }
            else
            {
                sum -= cntBalance[--balance];
            }

            cntBalance[balance]++;
            ans += sum;
        }

        return ans;
    }
};
