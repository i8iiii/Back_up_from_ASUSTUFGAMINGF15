//Problem 28
//URL: https://leetcode.com/problems/merge-two-sorted-lists/
//Level: Easy
//Last updated: 2024/12/8
/*Description: According to this problem, we are given 2 heads of two linked list, we have to merge these two linked list into one and then sort it.
Example:    

Example 1:
Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]

Example 2:
Input: list1 = [], list2 = [1,4]
Output: [1,4]

Example 3:
Input: list1 = [], list2 = []
Output: []
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* curNode = dummy;
        while (l1 && l2) {
            if (l1->val < l2->val) { //tranverse, merge and sort two linked lists
               curNode->next = l1; 
               l1 = l1->next;
            } else {
                curNode->next = l2;
                l2 = l2->next;
            }
            curNode = curNode->next;
        }

        if (l1 != NULL)
            curNode->next = l1; //add the rest of one of the two linked lists
        else 
            curNode->next = l2;

        ListNode* mergedList = dummy->next;
        delete dummy;
        return mergedList;
    }
};