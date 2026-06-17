/*
Problem: 3614. Process String with Special Operations II

Platform: LeetCode

Difficulty: Hard

Topics:
- Strings
- Simulation
- Reverse Processing

Approach:
1. Track only the length of the resulting string after each operation.
2. Store lengths in an array.
3. If k is outside the final length, return '.'.
4. Traverse operations in reverse:
   - '#' maps k to the corresponding half.
   - '%' reverses the index.
   - Letters are matched directly.
5. Avoid building the actual string, allowing handling of lengths up to 1e15.

Time Complexity: O(n)

Space Complexity: O(n)
*/
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr int N = 100000;
ll Len[N] = {0};

class Solution
{
public:
    char processStr(string s, long long k)
    {
        int n = s.size();
        ll L = 0;

        // Forward pass: compute resulting length after each operation
        for (int i = 0; i < n; i++)
        {
            char c = s[i];

            switch (c)
            {
            case '*':
                if (L > 0)
                    L--;
                break;

            case '#':
                L *= 2;
                break;

            case '%':
                break;

            default:
                L++;
            }

            Len[i] = L;
        }

        // k is out of bounds
        if (k >= L)
            return '.';

        // Reverse pass: trace kth character back
        for (int i = n - 1; i >= 0; i--)
        {
            char c = s[i];
            L = Len[i];

            if (L == 0)
                continue;

            switch (c)
            {
            case '*':
                // Nothing to do
                break;

            case '#':
                if (k >= L / 2)
                    k -= L / 2;
                break;

            case '%':
                k = L - 1 - k;
                break;

            default:
                if (k == L - 1)
                    return c;
            }
        }

        return '.';
    }
};