/*
Problem: 3286. Find a Safe Walk Through a Grid

Platform: LeetCode

Difficulty: Medium

Topics:
* Graph
* 0-1 BFS
* Shortest Path
* Matrix
* Deque

Problem Statement:
You are given an m x n binary matrix grid and an integer health.

You start from the top-left cell (0, 0) and want to reach the
bottom-right cell (m - 1, n - 1).

You can move in four directions (up, down, left, right).

Entering a cell with value 1 decreases your health by 1,
while entering a cell with value 0 does not reduce your health.

Return true if you can reach the destination with health remaining
greater than 0; otherwise, return false.

Example:
Input:
grid = [[0,1,0,0,0],
        [0,1,0,1,0],
        [0,0,0,1,0]]
health = 1

Output:
true

Approach:
1. Model the grid as a weighted graph where:
   - Moving into a safe cell (0) has cost 0.
   - Moving into an unsafe cell (1) has cost 1.
2. Use 0-1 BFS with a deque to compute the minimum health loss
   required to reach every cell.
3. Store the minimum cost (health lost) in a distance matrix.
4. If moving to a safe cell, push it to the front of the deque.
5. If moving to an unsafe cell, push it to the back.
6. After processing all reachable cells, compare the minimum health
   loss to the available health.
7. Return true if the minimum health loss is strictly less than
   the initial health; otherwise, return false.

Time Complexity: O(m × n)

Space Complexity: O(m × n)

Where:
m = Number of rows
n = Number of columns
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool findSafeWalk(vector<vector<int>> &grid, int health)
    {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));

        deque<pair<int, int>> dq;

        dist[0][0] = grid[0][0];
        dq.push_front({0, 0});

        int dir[5] = {-1, 0, 1, 0, -1};

        while (!dq.empty())
        {
            auto [x, y] = dq.front();
            dq.pop_front();

            for (int k = 0; k < 4; k++)
            {
                int nx = x + dir[k];
                int ny = y + dir[k + 1];

                if (nx < 0 || ny < 0 || nx >= m || ny >= n)
                    continue;

                int newCost = dist[x][y] + grid[nx][ny];

                if (newCost < dist[nx][ny])
                {
                    dist[nx][ny] = newCost;

                    if (grid[nx][ny] == 0)
                        dq.push_front({nx, ny});
                    else
                        dq.push_back({nx, ny});
                }
            }
        }

        return dist[m - 1][n - 1] < health;
    }
};