/*
Problem: 2130. Maximum Twin Sum of a Linked List

Platform: LeetCode

Difficulty: Medium

Topics:
- Linked List
- Two Pointers
- Fast & Slow Pointer
- In-place Reversal

Approach:
1. Use Fast and Slow pointers to find the middle of the linked list.
2. While finding the middle, reverse the first half of the list.
3. After reaching the middle:
   - 'rev' points to the reversed first half.
   - 'slow' points to the second half.
4. Traverse both halves simultaneously.
5. Calculate twin sum = firstHalfNode + secondHalfNode.
6. Keep track of the maximum twin sum.

Time Complexity: O(n)

Space Complexity: O(1)
*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    static int pairSum(ListNode *head)
    {
        ListNode *fast = head, *slow = head;
        ListNode *rev = NULL, *nextNode;

        while (fast)
        {
            fast = fast->next->next;

            nextNode = slow->next;
            slow->next = rev;
            rev = slow;
            slow = nextNode;
        }

        int ans = 0;

        while (slow)
        {
            ans = max(ans, rev->val + slow->val);

            rev = rev->next;
            slow = slow->next;
        }

        return ans;
    }
};