/*
Problem: 3534. Path Existence Queries in a Graph II

Platform: LeetCode

Difficulty: Hard

Topics:
* Graph
* Binary Lifting
* Sliding Window
* Sorting
* Binary Search

Problem Statement:
You are given an integer n representing the number of nodes in a graph,
labeled from 0 to n - 1.

You are also given an integer array nums and an integer maxDiff.

An undirected edge exists between nodes i and j if the absolute difference
between nums[i] and nums[j] is at most maxDiff.

For each query [u, v], determine the minimum number of edges required
to travel from node u to node v.

If no valid path exists, return -1.

Example 1:
Input:
n = 5
nums = [1,8,3,4,2]
maxDiff = 3
queries = [[0,3],[2,4]]

Output:
[1,1]

Explanation:
Node 0 can directly reach node 3.
Node 2 can directly reach node 4.

Example 2:
Input:
n = 5
nums = [5,3,1,9,10]
maxDiff = 2
queries = [[0,1],[0,2],[2,3],[4,3]]

Output:
[1,2,-1,1]

Explanation:
The shortest distances are:
0 → 1 = 1 edge
0 → 1 → 2 = 2 edges
No path exists from 2 to 3.
4 → 3 = 1 edge.

Approach:
1. Sort the nodes according to their values while remembering
   their original indices.
2. Build a sliding window to determine the farthest node reachable
   from every sorted position using maxDiff.
3. Store these jumps in the first level of a Binary Lifting table.
4. Build higher jump levels using dynamic programming.
5. For every query:
   - Convert both nodes into their positions in the sorted array.
   - Use Binary Lifting to compute the minimum number of jumps.
   - Return -1 if the destination cannot be reached.

Time Complexity: O((n + q) log n)

Space Complexity: O(n log n)

Where:
n = Number of nodes
q = Number of queries
*/

#include <bits/stdc++.h>
using namespace std;

constexpr int L = 18;
constexpr int N = 100001;

using pii = pair<int, int>;

int up[L][N];
int pos[N];
pii valueIndex[N];

class Solution
{
public:

    int minimumJumps(int u, int v, int maxLevel)
    {
        if (u == v)
            return 0;

        if (up[0][u] >= v)
            return 1;

        if (up[maxLevel - 1][u] < v)
            return -1;

        int jumps = 0;

        for (int j = maxLevel - 1; j >= 0; j--)
        {
            if (up[j][u] < v)
            {
                jumps += (1 << j);
                u = up[j][u];
            }
        }

        return jumps + 1;
    }

    vector<int> pathExistenceQueries(
        int n,
        vector<int>& nums,
        int maxDiff,
        vector<vector<int>>& queries)
    {

        int maxLevel = bit_width((unsigned)n) + 1;

        for (int i = 0; i < n; i++)
            valueIndex[i] = {nums[i], i};

        sort(valueIndex, valueIndex + n);

        for (int i = 0; i < n; i++)
            pos[valueIndex[i].second] = i;

        // Sliding Window
        for (int left = 0, right = 0; left < n; left++)
        {
            while (right + 1 < n &&
                   valueIndex[right + 1].first - valueIndex[left].first <= maxDiff)
            {
                right++;
            }

            up[0][left] = right;
        }

        // Binary Lifting
        for (int j = 1; j < maxLevel; j++)
        {
            for (int i = 0; i < n; i++)
            {
                up[j][i] = up[j - 1][up[j - 1][i]];
            }
        }

        vector<int> answer;

        for (auto &query : queries)
        {
            auto [u, v] = minmax(pos[query[0]], pos[query[1]]);

            answer.push_back(minimumJumps(u, v, maxLevel));
        }

        return answer;
    }
};