/*
Problem: 3756. Concatenate Non-Zero Digits and Multiply by Sum II

Platform: LeetCode

Difficulty: Medium

Topics:
* Math
* String
* Prefix Sum
* Queries
* Modular Arithmetic

Problem Statement:
You are given a string s consisting of digits and a list of queries.

For each query [l, r]:

1. Extract the substring s[l...r].
2. Concatenate all non-zero digits from the substring in their original order
   to form a new integer x.
3. If there are no non-zero digits, then x = 0.
4. Let sum be the sum of digits in x.
5. Return x × sum modulo (10^9 + 7).

Example 1:
Input:
s = "10203004"
queries = [[0,7],[1,3],[4,6]]

Output:
[12340,4,9]

Explanation:
Query [0,7]:
Non-zero digits = 1234
Sum = 10
Answer = 1234 × 10 = 12340

Query [1,3]:
Non-zero digits = 2
Sum = 2
Answer = 2 × 2 = 4

Query [4,6]:
Non-zero digits = 3
Sum = 3
Answer = 3 × 3 = 9

Approach:
1. Precompute powers of 10 modulo (10^9 + 7).
2. Build prefix information containing:
   - Concatenated non-zero number modulo MOD.
   - Count of non-zero digits.
   - Sum of digits.
3. For every query:
   - Compute digit sum using prefix sums.
   - Compute the concatenated number using modular arithmetic.
   - Multiply both values modulo MOD.
4. Return all answers.

Time Complexity:
O(n + q)

Space Complexity:
O(n)

Where:
n = Length of the string
q = Number of queries
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    static constexpr int MOD = 1e9 + 7;
    static constexpr int MAXN = 100001;

    static int power10[MAXN];

    using ll = long long;
    using Prefix = pair<pair<ll, int>, ll>;

    static Prefix prefix[MAXN];

public:
    static void computePowers()
    {
        if (power10[0])
            return;

        long long value = 1;
        power10[0] = 1;

        for (int i = 1; i < MAXN; i++)
        {
            value = (value * 10) % MOD;
            power10[i] = value;
        }
    }

    vector<int> sumAndMultiply(string s, vector<vector<int>> &queries)
    {
        computePowers();

        int n = s.size();

        long long number = 0;
        long long digitSum = 0;
        int nonZeroCount = 0;

        prefix[0] = {{0, 0}, 0};

        for (int i = 0; i < n; i++)
        {
            int digit = s[i] - '0';

            if (digit != 0)
            {
                number = (number * 10 + digit) % MOD;
                nonZeroCount++;
            }

            digitSum += digit;

            prefix[i + 1] = {{number, nonZeroCount}, digitSum};
        }

        vector<int> answer;

        for (auto &query : queries)
        {
            int left = query[0];
            int right = query[1] + 1;

            long long sum = prefix[right].second - prefix[left].second;

            if (sum < 0)
                sum += MOD;

            auto [leftInfo, rightInfo] =
                make_pair(prefix[left].first, prefix[right].first);

            long long leftNumber = leftInfo.first;
            long long rightNumber = rightInfo.first;

            int digitsAdded = rightInfo.second - leftInfo.second;

            long long shifted =
                (leftNumber * power10[digitsAdded]) % MOD;

            long long numberInRange =
                (rightNumber - shifted + MOD) % MOD;

            answer.push_back((numberInRange * sum) % MOD);
        }

        return answer;
    }
};

int Solution::power10[Solution::MAXN] = {0};
Solution::Prefix Solution::prefix[Solution::MAXN];