/*
Problem: 3558. Number of Ways to Assign Edge Weights I

Platform: LeetCode

Difficulty: Medium

Topics:
- Trees
- Graphs
- BFS
- Math

Approach:
1. Build the tree using degree count and XOR neighbor tracking.
2. Start from all leaf nodes except the root.
3. Peel the tree level by level (similar to topological trimming).
4. Each BFS layer represents one depth level from the deepest nodes.
5. Let the maximum depth be d.
6. Every edge on the root-to-deepest-node path can be assigned either 1 or 2.
7. Total assignments = 2^d.
8. Exactly half of these assignments produce an odd path sum.
9. Therefore answer = 2^(d - 1) mod (1e9 + 7).

Time Complexity: O(n)

Space Complexity: O(n)
*/

#include <bits/stdc++.h>
using namespace std;

struct Solution
{
    static constexpr unsigned assignEdgeWeights(const vector<vector<int>> &edges)
    {
        static constexpr unsigned mod = 1000000007;

        unsigned size = edges.size() + 1u;
        auto arr = make_unique<unsigned[]>(size * 3u);

        unsigned *const cnt = arr.get();
        unsigned *const sum = cnt + size;
        unsigned *right = sum + size;
        const unsigned *left = right;

        for (span<const int> e : edges)
        {
            unsigned u = e[0] - 1u;
            unsigned v = e[1] - 1u;

            ++cnt[u];
            ++cnt[v];

            sum[u] ^= v;
            sum[v] ^= u;
        }

        for (unsigned i = 1; i != size; ++i)
            if (cnt[i] == 1u)
                *right++ = i;

        unsigned res = 1;

        while (left != right)
        {
            span<const unsigned> curr(left, right);
            left = right;

            for (unsigned v : curr)
            {
                unsigned p = sum[v];

                if (p)
                {
                    sum[p] ^= v;

                    if (--cnt[p] == 1u)
                        *right++ = p;
                }
            }

            res %= mod;
            res *= 2u;
        }

        return res / 2u;
    }
};