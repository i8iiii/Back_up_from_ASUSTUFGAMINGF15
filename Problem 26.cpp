//Problem 26
//URL: https://leetcode.com/problems/palindrome-linked-list/
//Level: Easy
//Last updated: 2024/12/4
/*Description: According to this problem, we are given head, the head of a linked list and then we have to check that
is the given linked list is palindrome.

Example:    

Example 1:
Input: head = [1,2,2,1]
Output: true

Example 2:
Input: head = [3]
Output: true

Example 3:
Input: head = []
Output: false
*/
//Solution in C++ language
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (head == NULL)
            return false;
        if (head->next == NULL)
            return true;
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {        //find the start point of the second half of the linked list
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *prev = NULL, *temp, *curNode = slow;
        while (curNode) {                        //reverse the second half of the linked list
            temp = curNode->next;
            curNode->next = prev;
            prev = curNode;
            curNode = temp;
        }
        ListNode *first = head, *second = prev;
        while (second) {
            if (first->val != second->val)  //check if the linked list is palindrome    
                return false;               //expample: 1 2 2 1 --> 1 2 1 2 then compare the first half and the second half
            first = first->next;
            second = second->next;
        }
    return true;
    }
};