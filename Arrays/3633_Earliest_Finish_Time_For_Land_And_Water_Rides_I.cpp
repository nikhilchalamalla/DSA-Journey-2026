/*
Problem: 3633. Earliest Finish Time for Land and Water Rides I

Platform: LeetCode

Difficulty: Easy

Topics:
- Arrays
- Simulation

Approach:
1. Find the earliest finishing ride from the first category.
2. For each ride in the second category:
   - Start it either when it opens or when the first ride finishes.
   - Calculate the finishing time.
3. Repeat the same process in reverse order:
   - Water -> Land
   - Land -> Water
4. Return the minimum finishing time.

Time Complexity: O(n + m)

Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int calFinishTime(vector<int> &ls,
                      vector<int> &ld,
                      vector<int> &ws,
                      vector<int> &wd)
    {

        int mini = INT_MAX;

        for (int i = 0; i < ls.size(); i++)
        {
            mini = min(mini, ls[i] + ld[i]);
        }

        int ans = INT_MAX;

        for (int i = 0; i < ws.size(); i++)
        {
            ans = min(ans,
                      max(mini, ws[i]) + wd[i]);
        }

        return ans;
    }

    int earliestFinishTime(vector<int> &landStartTime,
                           vector<int> &landDuration,
                           vector<int> &waterStartTime,
                           vector<int> &waterDuration)
    {

        return min(
            calFinishTime(
                landStartTime,
                landDuration,
                waterStartTime,
                waterDuration),
            calFinishTime(
                waterStartTime,
                waterDuration,
                landStartTime,
                landDuration));
    }
};