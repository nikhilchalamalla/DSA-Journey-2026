```cpp
/*
Problem: 1358. Number of Substrings Containing All Three Characters

Platform: LeetCode

Difficulty: Medium

Topics:
* String
* Sliding Window
* Hashing
* Two Pointers

Problem Statement:
Given a string s consisting only of the characters 'a', 'b', and 'c'.

Return the number of substrings that contain at least one occurrence
of all three characters.

Example:
Input: s = "abcabc"
Output: 10

Approach:
1. Maintain the last occurrence index of characters 'a', 'b', and 'c'.
2. Initialize all last occurrence indices as -1.
3. Traverse the string from left to right.
4. Update the last occurrence of the current character.
5. Once all three characters have appeared, the minimum among the
   three last indices determines the earliest starting position of a
   valid substring ending at the current index.
6. Add (minimum last index + 1) to the answer.
7. Continue until the end of the string.

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
    int numberOfSubstrings(string s)
    {

        int ans = 0;

        // Last occurrence of 'a', 'b', and 'c'
        int last[3] = {-1, -1, -1};

        for (int i = 0; i < s.length(); i++)
        {

            last[s[i] - 'a'] = i;

            ans += min({last[0], last[1], last[2]}) + 1;
        }

        return ans;
    }
};
