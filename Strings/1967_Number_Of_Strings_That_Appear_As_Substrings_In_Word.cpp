```cpp
/*
Problem: 1967. Number of Strings That Appear as Substrings in Word

Platform: LeetCode

Difficulty: Easy

Topics:
- Strings
- String Matching

Approach:
1. Initialize a counter to store the number of matching patterns.
2. Traverse each string in the patterns array.
3. Use the built-in string function find() to check whether the current pattern
   exists as a substring inside the given word.
4. If find() does not return string::npos, the pattern exists, so increment the counter.
5. Return the final count.

Time Complexity: O(n × m)

Space Complexity: O(1)

Where:
n = number of strings in patterns
m = length of word
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numOfStrings(vector<string> &patterns, string word)
    {
        int count = 0;

        for (const string &s : patterns)
        {
            if (word.find(s) != string::npos)
            {
                count++;
            }
        }

        return count;
    }
};

auto init = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();
