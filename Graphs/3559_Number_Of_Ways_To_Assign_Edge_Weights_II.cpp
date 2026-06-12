/*
Problem: 3559. Number of Ways to Assign Edge Weights II

Platform: LeetCode

Difficulty: Hard

Topics:
- Trees
- Graphs
- Binary Lifting
- Lowest Common Ancestor (LCA)
- Math

Approach:
1. Build the tree using an adjacency list.
2. Precompute depths and binary lifting tables using DFS.
3. For each query (u, v):
   - Find the Lowest Common Ancestor (LCA).
   - Compute the path length:
     dist = depth[u] + depth[v] - 2 * depth[LCA]
4. If dist = 0, there are no edges in the path, so the answer is 0.
5. Otherwise:
   - Each edge can be assigned weight 1 or 2.
   - Total assignments = 2^dist.
   - Exactly half of them produce an odd path sum.
   - Answer = 2^(dist - 1) mod (1e9 + 7).
6. Precompute powers of 2 for fast query processing.

Time Complexity:
- Preprocessing: O(n log n)
- Each Query: O(log n)

Space Complexity:
- O(n log n)
*/

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    static const int MOD = 1000000007;

    vector<int> depth;
    vector<vector<int>> up;
    vector<vector<int>> graph;
    int LOG;

    void dfs(int node, int parent)
    {
        up[node][0] = parent;

        for (int j = 1; j < LOG; j++)
        {
            up[node][j] = up[up[node][j - 1]][j - 1];
        }

        for (int next : graph[node])
        {
            if (next == parent)
                continue;

            depth[next] = depth[node] + 1;
            dfs(next, node);
        }
    }

    int lca(int a, int b)
    {
        if (depth[a] < depth[b])
            swap(a, b);

        int diff = depth[a] - depth[b];

        for (int j = LOG - 1; j >= 0; j--)
        {
            if ((diff >> j) & 1)
            {
                a = up[a][j];
            }
        }

        if (a == b)
            return a;

        for (int j = LOG - 1; j >= 0; j--)
        {
            if (up[a][j] != up[b][j])
            {
                a = up[a][j];
                b = up[b][j];
            }
        }

        return up[a][0];
    }

    vector<int> assignEdgeWeights(vector<vector<int>> &edges, vector<vector<int>> &queries)
    {
        int n = edges.size() + 1;

        LOG = 17;
        while ((1 << LOG) <= n)
            LOG++;

        graph.assign(n + 1, {});
        for (auto &e : edges)
        {
            int u = e[0];
            int v = e[1];

            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        depth.assign(n + 1, 0);
        up.assign(n + 1, vector<int>(LOG, 1));

        dfs(1, 1);

        vector<int> pow2(n + 1, 1);
        for (int i = 1; i <= n; i++)
        {
            pow2[i] = (long long)pow2[i - 1] * 2 % MOD;
        }

        vector<int> ans;

        for (auto &q : queries)
        {
            int u = q[0];
            int v = q[1];

            int ancestor = lca(u, v);

            int dist = depth[u] + depth[v] - 2 * depth[ancestor];

            if (dist == 0)
            {
                ans.push_back(0);
            }
            else
            {
                ans.push_back(pow2[dist - 1]);
            }
        }

        return ans;
    }
};
