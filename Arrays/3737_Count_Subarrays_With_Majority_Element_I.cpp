```cpp
/*
Problem: 3737. Count Subarrays With Majority Element I

Platform: LeetCode

Difficulty: Medium

Topics:
- Arrays
- Brute Force
- Counting

Problem Statement:
You are given an integer array nums and an integer target.

Return the number of subarrays of nums in which target is the majority element.

The majority element of a subarray is the element that appears
strictly more than half of the times in that subarray.

Approach:

1. Iterate through every possible starting index.
2. For each starting index, extend the ending index one by one.
3. Maintain the count of occurrences of the target element.
4. Compute the current subarray length.
5. If the target appears more than half of the current subarray length,
   then it is the majority element.
6. Count all such valid subarrays.
7. Return the total count.

Time Complexity: O(n²)

Space Complexity: O(1)
*/
#include <bits/stdc++.h>
    using namespace std;

class Solution
{
public:
    long long countMajoritySubarrays(vector<int> &nums, int target)
    {
        int n = nums.size();
        long long ans = 0;

        for (int l = 0; l < n; l++)
        {
            int targetCount = 0;

            for (int r = l; r < n; r++)
            {
                if (nums[r] == target)
                {
                    targetCount++;
                }

                int len = r - l + 1;

                if (targetCount > len / 2)
                {
                    ans++;
                }
            }
        }

        return ans;
    }
};