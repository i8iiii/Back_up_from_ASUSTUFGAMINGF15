//Problem 24
//URL: https://leetcode.com/problems/linked-list-cycle/
//Level: Easy
//Last updated: 2024/12/3
/*Description: According to this problem, we are given head, the head of a linked list, determine if the linked list has a cycle in it.
Cycle means that some nodes will be reached by continously folowing the next pointer of those nodes.

Example:    

Example 1:
Input: head = [3,2,0,-4], pos = 1
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 1st node (0-indexed).

Example 2:
Input: head = [3,2,0,2,6,7,8], pos = 3
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 3rd node (0-indexed).

Example 3:
Input: head = [3,2], pos = -1
Output: false
Explanation: There is no cycle in the linked list because the next pointer of 2nd node is NULL.
*/
//Solution in C++ language
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *fast = head;
        ListNode *slow = head;

        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) return true;
        }
        
        return false;
    }
};