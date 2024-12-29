//Problem 22
//URL: https://leetcode.com/problems/add-two-numbers/
//Level: Medium
//Last updated: 2024/12/3
/*Description: According to this problem, we determine the sum of reversed two numbers by using linked list, making dummy head and allocate new node.
/*Example:    

Example 1:
Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.

Example 2:
Input: l1 = [1,1], l2 = [2,2]
Output: [3,3]
Explanation: 11 + 22 = 33.

Example 3:
Input: l1 = [0,2,5], l2 = [1,1]
Output: [1,3,5]
Explanation: 520 + 11 = 531.
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int bonus = 0;
        ListNode *fakeHead = new ListNode(0);
        ListNode *curNode = fakeHead->next;
        
        while (l1 != NULL || l2 != NULL || bonus != 0) {
            int val1 = (l1 != NULL) ? l1->val : 0;
            int val2 = (l2 != NULL) ? l2->val : 0;
            int sum = val1 + val2 + bonus;

            bonus = sum / 10;
            curNode = new ListNode(sum % 10);
            curNode = curNode->next;

            if (l1 != NULL) l1 = l1->next;
            if (l2 != NULL) l2 = l2->next;
        }
    ListNode* res = fakeHead->next;
    delete fakeHead;
    return res;
    }
};