/*
Problem: 3658. GCD of Odd and Even Sums

Platform: LeetCode

Difficulty: Easy

Topics:
* Math
* Number Theory
* GCD

Problem Statement:
You are given an integer n.

Compute the following two values:

1. sumOdd  = Sum of the smallest n positive odd numbers.
2. sumEven = Sum of the smallest n positive even numbers.

Return the greatest common divisor (GCD) of sumOdd and sumEven.

Example 1:
Input: n = 4

Output: 4

Explanation:
sumOdd = 1 + 3 + 5 + 7 = 16
sumEven = 2 + 4 + 6 + 8 = 20

GCD(16, 20) = 4.

Example 2:
Input: n = 5

Output: 5

Explanation:
sumOdd = 1 + 3 + 5 + 7 + 9 = 25
sumEven = 2 + 4 + 6 + 8 + 10 = 30

GCD(25, 30) = 5.

Approach:
1. The sum of the first n odd numbers is n².
2. The sum of the first n even numbers is n(n + 1).
3. We need GCD(n², n(n + 1)).
4. Since gcd(n, n + 1) = 1,
   gcd(n², n(n + 1)) = n.
5. Therefore, simply return n.

Time Complexity: O(1)

Space Complexity: O(1)

Where:
n = Given integer
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int gcdOfOddEvenSums(int n)
    {
        return n;
    }
};