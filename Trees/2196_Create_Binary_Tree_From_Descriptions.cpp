/*
Problem: 2196. Create Binary Tree From Descriptions

Platform: LeetCode

Difficulty: Medium

Topics:
- Trees
- Binary Tree
- Hash Map

Approach:
1. Create TreeNode objects for every unique value.
2. Connect parent and child nodes according to descriptions.
3. Track the root using XOR:
   - Add parent and child values.
   - Remove child values from root candidates.
4. The remaining value represents the root node.
5. Return the root TreeNode.

Time Complexity: O(n)

Space Complexity: O(n)
*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    TreeNode *createBinaryTree(vector<vector<int>> &A)
    {
        unordered_map<int, TreeNode *> nodes;
        nodes.reserve(A.size() + 1);
        int root = 0;

        for (auto &d : A)
        {
            int x = d[0], y = d[1], isLeft = d[2];

            if (!nodes.contains(x))
            {
                nodes[x] = new TreeNode(x);
                root ^= x;
            }

            if (!nodes.contains(y))
            {
                nodes[y] = new TreeNode(y);
                root ^= y;
            }

            if (isLeft)
                nodes[x]->left = nodes[y];
            else
                nodes[x]->right = nodes[y];

            root ^= y;
        }

        return nodes[root];
    }
};