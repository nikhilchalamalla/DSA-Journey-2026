/*
Problem: 1979. Find Greatest Common Divisor of Array

Platform: LeetCode

Difficulty: Easy

Topics:
* Math
* Array
* Number Theory
* Euclidean Algorithm

Problem Statement:
Given an integer array nums, return the greatest common divisor (GCD)
of the smallest number and the largest number in the array.

The greatest common divisor of two integers is the largest positive
integer that divides both numbers exactly.

Example 1:
Input: nums = [2,5,6,9,10]
Output: 2

Explanation:
Smallest element = 2
Largest element = 10
GCD(2,10) = 2

Example 2:
Input: nums = [7,5,6,8,3]
Output: 1

Explanation:
Smallest element = 3
Largest element = 8
GCD(3,8) = 1

Approach:
1. Find the minimum element in the array.
2. Find the maximum element in the array.
3. Compute the GCD of the minimum and maximum elements
   using the Euclidean Algorithm.
4. Return the computed GCD.

Time Complexity: O(n + log(max(nums)))

Space Complexity: O(1)

Where:
n = Number of elements in the array
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int gcd(int a, int b)
    {
        while (b != 0)
        {
            int temp = b;
            b = a % b;
            a = temp;
        }

        return a;
    }

    int findGCD(vector<int>& nums)
    {
        int mn = *min_element(nums.begin(), nums.end());

        int mx = *max_element(nums.begin(), nums.end());

        return gcd(mn, mx);
    }
};