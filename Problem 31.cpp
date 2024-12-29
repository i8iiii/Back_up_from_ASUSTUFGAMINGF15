//Problem 31
//URL: https://leetcode.com/problems/reverse-linked-list-ii/description/
//Level: Med
//Last updated: 2024/12/15
/*Description: According to this problem, we have to reverse the nodes from left to right in certain distances.
Example:    

Example 1:
Input: head = [1,2,3,4,5], left = 2, right = 4
Output: [1,4,3,2,5]

Example 2:
Input: head = [1,2,3,4,5], left = 1, right = 1
Output: [1,2,3,4,5]

Example 3:
Input: head = [], left = 1, right = 1
Output: []
Solution in C++ language
 */

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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right)
            return head;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* hold = dummy;

        for (int i = 1; i < left; i++) {
            hold = hold->next;
        }

        ListNode* node = hold->next;  
        ListNode* holdLeft = node; 
           
        for (int i = 0; i < right - left; i++) {
            ListNode* temp = node->next;
            node->next = temp->next;
            temp->next = holdLeft;
            holdLeft = temp;
            hold->next = temp;
        }

    ListNode* res = dummy->next;
    delete dummy
    return res;
    }
};