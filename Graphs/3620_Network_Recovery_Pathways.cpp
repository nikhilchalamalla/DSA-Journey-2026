/*
Problem: 3620. Network Recovery Pathways

Platform: LeetCode

Difficulty: Hard

Topics:
* Graph
* Directed Acyclic Graph (DAG)
* Topological Sort
* Binary Search
* Dynamic Programming

Problem Statement:
You are given a Directed Acyclic Graph (DAG) with n nodes numbered
from 0 to n-1.

Each edge is represented as:
edges[i] = [u, v, cost]

Some nodes are offline.

A path from node 0 to node n-1 is valid if:

1. Every intermediate node is online.
2. The total recovery cost of the path does not exceed k.

The score of a valid path is defined as the minimum edge cost
present on that path.

Return the maximum possible path score among all valid paths.
If no valid path exists, return -1.

Example:

Input:
edges = [[0,1,5],[1,3,10],[0,2,3],[2,3,4]]
online = [true,true,true,true]
k = 10

Output:
3

Approach:
1. Build the DAG using an adjacency list.
2. Compute the Topological Order using Kahn's Algorithm.
3. Apply Binary Search on the answer (minimum edge cost).
4. For every candidate score:
   - Ignore edges whose weight is smaller than the candidate.
   - Ignore offline intermediate nodes.
   - Perform Dynamic Programming on the Topological Order to
     calculate the minimum path cost.
5. If the destination can be reached within cost k,
   increase the candidate score.
6. Otherwise, decrease it.
7. The maximum feasible score is the answer.

Time Complexity:
O((N + M) * logW)

Space Complexity:
O(N + M)

Where:
N = Number of nodes
M = Number of edges
W = Maximum edge weight
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findMaxPathScore(vector<vector<int>> &edges,
                         vector<bool> &online,
                         long long k)
    {
        int n = online.size();

        vector<vector<pair<int, int>>> graph(n);
        vector<int> indegree(n, 0);

        int maxCost = 0;

        for (auto &e : edges)
        {
            int u = e[0];
            int v = e[1];
            int w = e[2];

            graph[u].push_back({v, w});
            indegree[v]++;

            maxCost = max(maxCost, w);
        }

        // Topological Sort
        vector<int> topo;
        queue<int> q;

        vector<int> deg = indegree;

        for (int i = 0; i < n; i++)
        {
            if (deg[i] == 0)
                q.push(i);
        }

        while (!q.empty())
        {
            int u = q.front();
            q.pop();

            topo.push_back(u);

            for (auto &[v, w] : graph[u])
            {
                if (--deg[v] == 0)
                    q.push(v);
            }
        }

        auto check = [&](int limit)
        {
            const long long INF = 4e18;

            vector<long long> dp(n, INF);

            dp[0] = 0;

            for (int u : topo)
            {
                if (dp[u] == INF)
                    continue;

                if (u != 0 && u != n - 1 && !online[u])
                    continue;

                for (auto &[v, w] : graph[u])
                {
                    if (w < limit)
                        continue;

                    if (v != n - 1 && !online[v])
                        continue;

                    dp[v] = min(dp[v], dp[u] + w);
                }
            }

            return dp[n - 1] <= k;
        };

        int lo = 0;
        int hi = maxCost;
        int ans = -1;

        while (lo <= hi)
        {
            int mid = lo + (hi - lo) / 2;

            if (check(mid))
            {
                ans = mid;
                lo = mid + 1;
            }
            else
            {
                hi = mid - 1;
            }
        }

        return ans;
    }
};