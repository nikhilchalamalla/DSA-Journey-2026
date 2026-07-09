/*
Problem: 3532. Path Existence Queries in a Graph I

Platform: LeetCode

Difficulty: Medium

Topics:
* Graph
* Connected Components
* Array
* Prefix Processing

Problem Statement:
You are given an integer n representing the number of nodes in a graph,
labeled from 0 to n - 1.

You are also given a sorted integer array nums and an integer maxDiff.

An undirected edge exists between nodes i and j if the absolute difference
between nums[i] and nums[j] is at most maxDiff.

For each query [u, v], determine whether there exists a path between
node u and node v.

Return a boolean array containing the answer for every query.

Example 1:
Input:
n = 2
nums = [1,3]
maxDiff = 1
queries = [[0,0],[0,1]]

Output:
[true,false]

Explanation:
Node 0 is connected to itself.
There is no edge between node 0 and node 1 because
|1 - 3| = 2 > maxDiff.

Example 2:
Input:
n = 4
nums = [2,5,6,8]
maxDiff = 2
queries = [[0,1],[0,2],[1,3],[2,3]]

Output:
[false,false,true,true]

Approach:
1. Since nums is sorted, consecutive elements determine connected components.
2. Traverse the array from left to right.
3. If the difference between consecutive numbers exceeds maxDiff,
   start a new component.
4. Assign every index a component ID.
5. For each query, simply check whether both nodes belong
   to the same component.
6. If they do, a path exists; otherwise, it does not.

Time Complexity: O(n + q)

Space Complexity: O(n)

Where:
n = Number of nodes
q = Number of queries
*/

#include <bits/stdc++.h>
using namespace std;

int comp[100000];

class Solution
{
public:
    static vector<bool> pathExistenceQueries(
        int n,
        vector<int> &nums,
        int maxDiff,
        vector<vector<int>> &queries)
    {
        int q = queries.size();
        vector<bool> ans(q);

        int component = 0;
        comp[0] = component;

        int prev = nums[0];

        for (int i = 1; i < n; i++)
        {
            if (prev + maxDiff < nums[i])
                component++;

            comp[i] = component;
            prev = nums[i];
        }

        for (int i = 0; i < q; i++)
        {
            int u = queries[i][0];
            int v = queries[i][1];

            ans[i] = (comp[u] == comp[v]);
        }

        return ans;
    }
};