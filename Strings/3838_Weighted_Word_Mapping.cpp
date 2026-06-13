/*
Problem: 3838. Weighted Word Mapping

Platform: LeetCode

Difficulty: Easy

Topics:
- Strings
- Arrays
- Simulation

Approach:
1. For each word, calculate its total weight by summing
   the weights of all characters.
2. Take the total weight modulo 26.
3. Convert the result to a character using reverse
   alphabetical mapping:
   0 -> 'z', 1 -> 'y', ..., 25 -> 'a'.
4. Append the mapped character to the answer string.
5. Return the final constructed string.

Time Complexity: O(N × M)
- N = number of words
- M = average word length

Space Complexity: O(1)
(excluding output string)
*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string mapWordWeights(vector<string> &words, vector<int> &weights)
    {
        string result;

        for (const string &word : words)
        {
            int sumWeight = 0;

            for (char ch : word)
            {
                sumWeight += weights[ch - 'a'];
            }

            int value = sumWeight % 26;

            result.push_back(char('z' - value));
        }

        return result;
    }
};