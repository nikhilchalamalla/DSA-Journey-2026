/*
Problem: 1846. Maximum Element After Decreasing and Rearranging

Platform: LeetCode

Difficulty: Medium

Topics:
- Greedy
- Sorting
- Arrays

Approach:
1. Sort the array in non-decreasing order.
2. Set the first element to 1.
3. Traverse the remaining elements:
   - If the current element is greater than the previous element by more than 1,
     reduce it to previous + 1.
4. The last element becomes the maximum possible value.
5. Return the last element.

Time Complexity: O(n log n)

Space Complexity: O(1)

Where:
n = size of the array
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int> &arr)
    {
        sort(arr.begin(), arr.end());

        int n = arr.size();

        arr[0] = 1;

        for (int i = 1; i < n; i++)
        {
            if (arr[i] - arr[i - 1] > 1)
            {
                arr[i] = arr[i - 1] + 1;
            }
        }

        return arr.back();
    }
};

auto init = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();