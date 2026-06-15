/*
Problem: 2095. Delete the Middle Node of a Linked List

Platform: LeetCode

Difficulty: Medium

Topics:
- Linked List
- Two Pointers
- Fast & Slow Pointer

Approach:
1. If the linked list contains only one node,
   return nullptr since deleting the middle node
   leaves an empty list.

2. Use two pointers:
   - slow moves one step at a time.
   - fast moves two steps at a time.

3. Position slow one node before the middle node.

4. When fast reaches the end,
   slow->next will be the middle node.

5. Delete the middle node by skipping it:
   slow->next = slow->next->next.

6. Return the modified head.

Time Complexity: O(n)

Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    ListNode *deleteMiddle(ListNode *head)
    {
        if (!head->next)
            return nullptr;

        ListNode *slow = head;
        ListNode *fast = slow->next->next;

        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        slow->next = slow->next->next;
        return head;
    }
};