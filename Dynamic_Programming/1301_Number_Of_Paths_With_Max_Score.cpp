/*
Problem: 1301. Number of Paths with Max Score

Platform: LeetCode

Difficulty: Hard

Topics:
* Dynamic Programming
* Matrix
* Graph
* Simulation

Problem Statement:
You are given a square board of characters.

- 'S' represents the starting cell (bottom-right).
- 'E' represents the ending cell (top-left).
- Digits ('1' to '9') represent the score collected.
- 'X' represents an obstacle.

You can move only:
1. Up
2. Left
3. Upper-Left Diagonal

Return an array containing:
1. Maximum score that can be collected.
2. Number of paths achieving that maximum score.

If no path exists, return {0, 0}.

Example:

Input:
board = ["E23","2X2","12S"]

Output:
[7,1]

Approach:
1. Use Dynamic Programming.
2. Maintain two DP tables:
   - maxScore[i][j] → Maximum score obtainable from cell (i,j).
   - ways[i][j] → Number of maximum-score paths.
3. Traverse from bottom-right (S) towards top-left (E).
4. For every cell:
   - Check Down, Right and Down-Right cells
     (reverse of Up, Left, Diagonal moves).
   - Choose the maximum score among them.
   - If multiple directions give the same score,
     add their number of ways.
5. Ignore obstacle cells ('X').
6. Ignore characters 'S' and 'E' while adding score.
7. Return the score and number of optimal paths.

Time Complexity:
O(n²)

Space Complexity:
O(n²)

Where:
n = Size of the board
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> pathsWithMaxScore(vector<string> &board)
    {
        int mod = 1e9 + 7;
        int n = board.size();

        vector<vector<int>> maxScore(n, vector<int>(n, -1));
        vector<vector<int>> ways(n, vector<int>(n, 0));

        maxScore[n - 1][n - 1] = 0;
        ways[n - 1][n - 1] = 1;

        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = n - 1; j >= 0; j--)
            {
                if (board[i][j] == 'X')
                    continue;

                if (i == n - 1 && j == n - 1)
                    continue;

                int bestScore = -1;
                long long totalWays = 0;

                // Down
                if (i + 1 < n && maxScore[i + 1][j] != -1)
                {
                    if (maxScore[i + 1][j] > bestScore)
                    {
                        bestScore = maxScore[i + 1][j];
                        totalWays = ways[i + 1][j];
                    }
                    else if (maxScore[i + 1][j] == bestScore)
                    {
                        totalWays =
                            (totalWays + ways[i + 1][j]) % mod;
                    }
                }

                // Right
                if (j + 1 < n && maxScore[i][j + 1] != -1)
                {
                    if (maxScore[i][j + 1] > bestScore)
                    {
                        bestScore = maxScore[i][j + 1];
                        totalWays = ways[i][j + 1];
                    }
                    else if (maxScore[i][j + 1] == bestScore)
                    {
                        totalWays =
                            (totalWays + ways[i][j + 1]) % mod;
                    }
                }

                // Diagonal
                if (i + 1 < n && j + 1 < n &&
                    maxScore[i + 1][j + 1] != -1)
                {
                    if (maxScore[i + 1][j + 1] > bestScore)
                    {
                        bestScore = maxScore[i + 1][j + 1];
                        totalWays = ways[i + 1][j + 1];
                    }
                    else if (maxScore[i + 1][j + 1] == bestScore)
                    {
                        totalWays =
                            (totalWays + ways[i + 1][j + 1]) % mod;
                    }
                }

                if (bestScore == -1)
                    continue;

                int curr = 0;

                if (board[i][j] >= '1' && board[i][j] <= '9')
                    curr = board[i][j] - '0';

                maxScore[i][j] = bestScore + curr;
                ways[i][j] = totalWays % mod;
            }
        }

        if (maxScore[0][0] == -1)
            return {0, 0};

        return {maxScore[0][0], ways[0][0]};
    }
};