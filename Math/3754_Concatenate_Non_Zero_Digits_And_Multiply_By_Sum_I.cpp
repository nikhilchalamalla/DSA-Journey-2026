/*
Problem: 3754. Concatenate Non-Zero Digits and Multiply by Sum I

Platform: LeetCode

Difficulty: Easy

Topics:
* Math
* String
* Simulation

Problem Statement:
You are given an integer n.

Form a new integer x by concatenating all the non-zero digits of n
in their original order. If there are no non-zero digits, x = 0.

Let sum be the sum of digits in x.

Return the value of x * sum.

Example 1:
Input: n = 10203004
Output: 12340

Explanation:
The non-zero digits are 1, 2, 3 and 4.
Thus, x = 1234.
Sum of digits = 1 + 2 + 3 + 4 = 10.
Answer = 1234 × 10 = 12340.

Example 2:
Input: n = 1000
Output: 1

Explanation:
The only non-zero digit is 1.
Thus, x = 1 and sum = 1.
Answer = 1 × 1 = 1.

Approach:
1. Convert the integer into a string.
2. Traverse each digit.
3. Ignore all zero digits.
4. Build a new number x by appending every non-zero digit.
5. Simultaneously calculate the sum of all non-zero digits.
6. Return x multiplied by the sum.

Time Complexity: O(d)

Space Complexity: O(d)

Where:
d = Number of digits in n
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long sumAndMultiply(int n)
    {
        long long x = 0;
        long long sum = 0;

        for (char c : to_string(n))
        {
            if (c != '0')
            {
                x = x * 10 + (c - '0');
                sum += (c - '0');
            }
        }

        return x * sum;
    }
};