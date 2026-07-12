/*
Problem: 1331. Rank Transform of an Array

Platform: LeetCode

Difficulty: Easy

Topics:
* Array
* Sorting
* Hash Table

Problem Statement:
Given an array of integers arr, replace each element with its rank.

The rank represents how large the element is and follows these rules:

1. Rank is an integer starting from 1.
2. The larger the element, the larger the rank.
3. Equal elements must have the same rank.
4. The rank should be as small as possible.

Return the transformed array.

Example 1:
Input:
arr = [40,10,20,30]

Output:
[4,1,2,3]

Explanation:
10 is the smallest element, so its rank is 1.
20 is the second smallest, so its rank is 2.
30 is the third smallest, so its rank is 3.
40 is the largest, so its rank is 4.

Example 2:
Input:
arr = [100,100,100]

Output:
[1,1,1]

Explanation:
All elements are equal, so they share the same rank.

Example 3:
Input:
arr = [37,12,28,9,100,56,80,5,12]

Output:
[5,3,4,2,8,6,7,1,3]

Approach:
1. Store every element along with its original index.
2. Sort the elements based on their values.
3. Traverse the sorted array.
4. Assign the same rank to duplicate values.
5. Assign a new rank whenever a different value is encountered.
6. Store the rank back at the original index.
7. Return the final ranked array.

Time Complexity: O(n log n)

Space Complexity: O(n)

Where:
n = Number of elements in the array
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> arrayRankTransform(vector<int>& arr)
    {
        vector<pair<int, int>> temp;

        for (int i = 0; i < arr.size(); i++)
        {
            temp.push_back({arr[i], i});
        }

        sort(temp.begin(), temp.end());

        vector<int> answer(arr.size());

        int rank = 0;

        for (int i = 0; i < temp.size(); i++)
        {
            if (i > 0 && temp[i].first == temp[i - 1].first)
            {
                answer[temp[i].second] = answer[temp[i - 1].second];
            }
            else
            {
                answer[temp[i].second] = ++rank;
            }
        }

        return answer;
    }
};