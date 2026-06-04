/*
Problem: 3751. Total Waviness of Numbers in Range I

Platform: LeetCode

Difficulty: Medium

Topics:
- Math
- Simulation
- String Processing
- Brute Force

Approach:
1. Convert each number in the range into a string.
2. Check every middle digit.
3. A digit is:
   - Peak if greater than both neighbors.
   - Valley if smaller than both neighbors.
4. Count peaks and valleys for each number.
5. Sum the waviness of all numbers in the given range.

Time Complexity: O((num2 - num1 + 1) * d)

where d = number of digits

Space Complexity: O(d)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int waviness(int x)
    {

        string s = to_string(x);

        int cnt = 0;

        for (int i = 1; i < (int)s.size() - 1; i++)
        {

            if ((s[i] > s[i - 1] && s[i] > s[i + 1]) ||
                (s[i] < s[i - 1] && s[i] < s[i + 1]))
            {

                cnt++;
            }
        }

        return cnt;
    }

    int totalWaviness(int num1, int num2)
    {

        long long ans = 0;

        for (int x = num1; x <= num2; x++)
        {
            ans += waviness(x);
        }

        return ans;
    }
};