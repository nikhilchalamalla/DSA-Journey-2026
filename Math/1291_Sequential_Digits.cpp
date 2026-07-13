/*
Problem: 1291. Sequential Digits

Platform: LeetCode

Difficulty: Medium

Topics:
* Math
* Enumeration
* Breadth-First Search (BFS)

Problem Statement:
An integer has sequential digits if and only if each digit
is exactly one greater than the previous digit.

Given two integers low and high, return a sorted list of all
the integers in the range [low, high] that have sequential digits.

Example 1:
Input:
low = 100
high = 300

Output:
[123,234]

Explanation:
The sequential digit numbers between 100 and 300 are
123 and 234.

Example 2:
Input:
low = 1000
high = 13000

Output:
[1234,2345,3456,4567,5678,6789,12345]

Explanation:
These are all sequential digit numbers within the given range.

Approach:
1. Generate all possible sequential digit numbers.
2. Start with the single-digit numbers 1 to 9.
3. For each generated number, append the next consecutive digit
   if it is less than or equal to 9.
4. Store all generated sequential numbers.
5. Traverse the generated list.
6. Select only the numbers that lie within the range [low, high].
7. Return the resulting list.

Time Complexity: O(1)

Space Complexity: O(1)

Where:
There are only 36 possible sequential digit numbers,
so the work is constant.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    inline static int sequentialNumbers[45];

    inline static bool initialized = []()
    {
        int size = 0;

        for (int digit = 1; digit <= 9; digit++)
        {
            sequentialNumbers[size++] = digit;
        }

        for (int i = 0; i < size; i++)
        {
            int lastDigit = sequentialNumbers[i] % 10;

            if (lastDigit < 9)
            {
                sequentialNumbers[size++] =
                    sequentialNumbers[i] * 10 + lastDigit + 1;
            }
        }

        return true;
    }();

    vector<int> sequentialDigits(int low, int high)
    {
        vector<int> answer;

        for (int number : sequentialNumbers)
        {
            if (number >= low && number <= high)
            {
                answer.push_back(number);
            }
        }

        return answer;
    }
};