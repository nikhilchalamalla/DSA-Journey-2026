/*
Problem: 2161. Partition Array According to Given Pivot

Platform: LeetCode

Difficulty: Medium

Topics:
- Arrays
- Two Pointers
- Simulation

Approach:
1. Store elements less than pivot at the beginning.
2. Store elements greater than pivot separately while maintaining order.
3. Count the number of pivot elements.
4. Place all pivot values in the middle.
5. Append elements greater than pivot.

Time Complexity: O(n)

Space Complexity: O(n)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    static vector<int> pivotArray(vector<int> &nums, int pivot)
    {
        int n = nums.size();

        if (n == 1)
            return nums;

        int R[n];
        int l = 0, r = 0;

        for (int x : nums)
        {
            nums[l] = R[r] = x;

            l += (x < pivot);
            r += (x > pivot);
        }

        int m = n - r - l;

        auto it_m = nums.begin() + l;

        fill(it_m, it_m + m, pivot);

        copy(R, R + r, it_m + m);

        return nums;
    }
};