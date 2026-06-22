/*
Problem: 1189. Maximum Number of Balloons

Platform: LeetCode

Difficulty: Easy

Topics:

* Strings
* Hashing
* Frequency Counting

Approach:

1. Count the frequency of required characters:
   b, a, l, o, n.
2. The word "balloon" requires:

   * b = 1
   * a = 1
   * l = 2
   * o = 2
   * n = 1
3. Count occurrences of each required character.
4. Divide counts of 'l' and 'o' by 2 since they appear twice.
5. The minimum among all required counts gives the maximum number of times
   "balloon" can be formed.

Time Complexity: O(n)

Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxNumberOfBalloons(string text)
    {
        int freq[5] = {0};
        string target = "balon";

        ``` for (char ch : text)
        {
            for (int i = 0; i < 5; i++)
            {
                if (ch == target[i])
                {
                    freq[i]++;
                }
            }
        }

        return min({freq[0],
                    freq[1],
                    freq[2] / 2,
                    freq[3] / 2,
                    freq[4]});
    }
    ```
};
