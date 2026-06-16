/*
Problem: 3612. Process String with Special Operations I

Platform: LeetCode

Difficulty: Medium

Topics:
- Strings
- Simulation

Approach:
1. Traverse the string from left to right.
2. Maintain a result string.
3. For each character:
   - Letter -> append to result.
   - '*' -> remove last character if present.
   - '#' -> duplicate the current result.
   - '%' -> reverse the current result.
4. Return the final processed string.

Time Complexity: O(n * m)
where m is the current size of the result string.

Space Complexity: O(m)
*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string processStr(string s)
    {
        string res;
        int n = s.length();

        for (int i = 0; i < n; i++)
        {
            char ch = s[i];

            if (ch == '*')
            {
                if (res.length() != 0)
                {
                    res.pop_back();
                }
            }
            else if (ch == '#')
            {
                res += res;
            }
            else if (ch == '%')
            {
                reverse(res.begin(), res.end());
            }
            else if (ch >= 'a' && ch <= 'z')
            {
                res.push_back(ch);
            }
        }

        return res;
    }
};