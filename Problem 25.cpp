//Problem 25
//URL: https://leetcode.com/problems/reverse-linked-list/
//Level: Easy
//Last updated: 2024/12/4
/*Description: According to this problem, we are given head, the head of a linked list and then reverse the linked list.

Example:    

Example 1:
Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]

Example 2:
Input: head = [3]
Output: [3]

Example 3:
Input: head = []
Output: []
*/
//Solution in C++ language
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        int count = 0;
        if (head == NULL || head->next == NULL)
            return head;
        ListNode* dummyHead = head;
        ListNode* curNode = dummyHead;
        ListNode* temp;
        while (curNode->next) {                               //   sample of reverse linked list (when temp reach a node, make it be head and then point to the old head, then the old head will point to temp->next)              
            temp = curNode->next;                             //       1->2->3->4
            curNode->next = curNode->next->next;              //       2->1->3->4
            temp->next = dummyHead;                           //       3->2->1->4
            dummyHead = temp;                                 //       4->3->2->1
        }
        return temp;
    }
};