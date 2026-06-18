/*
Problem: 1344. Angle Between Hands of a Clock

Platform: LeetCode

Difficulty: Medium

Topics:
- Math
- Geometry

Approach:
1. Calculate the hour hand position:
   hour + minutes / 60.0
2. The relative movement between hour and minute hands
   is 11 times the hour position modulo 12.
3. Compute the difference between the two hands.
4. Take the smaller angle between them.
5. Convert clock units to degrees by multiplying by 30.

Time Complexity: O(1)

Space Complexity: O(1)
*/

#include<bits/stdc++.h>
using namespace std;

class Solution { public: double angleClock(int hour, int minutes) { double x = hour + minutes / 60.0; double diff = fmod(11.0 * x, 12.0); return min(diff, 12.0 - diff) * 30.0; } };