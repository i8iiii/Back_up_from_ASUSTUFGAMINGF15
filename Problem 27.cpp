//Problem 27
//URL: https://leetcode.com/problems/remove-linked-list-elements/
//Level: Easy
//Last updated: 2024/12/18
/*Description: According to this problem, we are given head, the head of a linked list and then delete nodes that have the same value with the target value.

Example:    

Example 1:
Input: head = [1,2,6,3,4,5,6], val = 6
Output: [1,2,3,4,5]

Example 2:
Input: head = [3], val = 1
Output: [3]

Example 3:
Input: head = [5,5,5,5,5,5], val = 5
Output: []
*/
//Solution in C++ language
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* temp = head;
        ListNode* prev = dummy;
        while (temp) {
            if (temp->val == val)
                prev->next = temp->next;
            else prev = temp;
            temp = temp->next;
        }
    return dummy->next;
    }
};