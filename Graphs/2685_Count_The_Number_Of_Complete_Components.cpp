/*
Problem: 2685. Count the Number of Complete Components

Platform: LeetCode

Difficulty: Medium

Topics:
* Graph
* Depth-First Search (DFS)
* Connected Components

Problem Statement:
You are given an integer n representing the number of vertices
in an undirected graph labeled from 0 to n - 1.

You are also given a 2D integer array edges where
edges[i] = [ai, bi] represents an undirected edge
between vertices ai and bi.

Return the number of complete connected components in the graph.

A connected component is complete if every pair of distinct
vertices in the component has an edge connecting them.

Example 1:
Input:
n = 6
edges = [[0,1],[0,2],[1,2],[3,4]]

Output:
3

Explanation:
The graph contains three complete connected components:
{0,1,2}, {3,4}, and {5}.

Example 2:
Input:
n = 6
edges = [[0,1],[0,2],[1,2],[3,4],[3,5]]

Output:
1

Explanation:
Only the component {0,1,2} is complete.
The component {3,4,5} is not complete because
there is no edge between vertices 4 and 5.

Approach:
1. Build the graph using an adjacency list.
2. Traverse every unvisited node using DFS.
3. Store all vertices belonging to the current connected component.
4. For every vertex in the component, verify that its degree equals
   (component size - 1).
5. If every vertex satisfies the condition, the component is complete.
6. Count such complete components and return the answer.

Time Complexity: O(n + m)

Space Complexity: O(n + m)

Where:
n = Number of vertices
m = Number of edges
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void dfs(
        int node,
        vector<vector<int>>& adj,
        vector<bool>& visited,
        vector<int>& component)
    {
        visited[node] = true;
        component.push_back(node);

        for (int neighbor : adj[node])
        {
            if (!visited[neighbor])
                dfs(neighbor, adj, visited, component);
        }
    }

    int countCompleteComponents(
        int n,
        vector<vector<int>>& edges)
    {
        vector<vector<int>> adj(n);

        for (auto& edge : edges)
        {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<bool> visited(n, false);

        int completeComponents = 0;

        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                vector<int> component;

                dfs(i, adj, visited, component);

                bool isComplete = true;

                for (int node : component)
                {
                    if (adj[node].size() != component.size() - 1)
                    {
                        isComplete = false;
                        break;
                    }
                }

                if (isComplete)
                    completeComponents++;
            }
        }

        return completeComponents;
    }
};