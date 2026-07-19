/*
Problem: 1081. Smallest Subsequence of Distinct Characters

Platform: LeetCode

Difficulty: Medium

Topics:
* Stack
* Greedy
* String
* Monotonic Stack

Problem Statement:
Given a string s, return the lexicographically smallest
subsequence of s that contains all the distinct characters
of s exactly once.

Example 1:
Input: s = "bcabc"

Output: "abc"

Explanation:
The smallest subsequence containing every distinct character
exactly once is "abc".

Example 2:
Input: s = "cbacdcbc"

Output: "acdb"

Explanation:
The lexicographically smallest valid subsequence is "acdb".

Approach:
1. Count the frequency of every character.
2. Traverse the string.
3. If a character is already included, skip it.
4. While the current character is smaller than the top of the stack
   and the top character appears later again, remove the top.
5. Push the current character and mark it as visited.
6. The stack forms the required answer.

Time Complexity: O(n)

Space Complexity: O(1)

Where:
n = Length of the string
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string smallestSubsequence(string s)
    {
        int freq[27] = {0};
        bitset<27> seen;
        string stack;

        for (auto &c : s)
            freq[c & 31]++;

        for (auto &c : s)
        {
            int x = c & 31;
            freq[x]--;

            if (seen.test(x))
                continue;

            while (!stack.empty() &&
                   stack.back() > c &&
                   freq[stack.back() & 31])
            {
                seen.reset(stack.back() & 31);
                stack.pop_back();
            }

            stack.push_back(c);
            seen.set(x);
        }

        return stack;
    }
};