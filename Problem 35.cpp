//Problem 35
//URL: https://leetcode.com/problems/merge-in-between-linked-lists/
//Level: Med
//Last updated: 2024/12/18
/*Description: According to this problem, we have to merge two list into one by remove ath node to bth node of list 1 and put list 2 in their place.
Example:    

Example 1:
Input: list1 = [10,1,13,6,9,5], a = 3, b = 4, list2 = [1000000,1000001,1000002]
Output: [10,1,13,1000000,1000001,1000002,5]
Explanation: We remove the nodes 3 and 4 and put the entire list2 in their place. 

Example 2:
Input: list1 = [10,15,220,4,9,3], a = 1, b = 2, list2 = [1000000]
Output: [10,1000000,4,9,3]
Explanation: We remove the nodes 1 and 2 and put the entire list2 in their place. 

Example 3:
Input: list1 = [1,1,1,1,1,1,1,1], a = 2, b = 5, list2 = [2,5,7,3]
Output: [1,1,2,5,7,3,1,1]
Explanation: We remove the nodes 2 and 2 and put the entire list2 in their place. 

3 <= list1.length <= 104
1 <= a <= b < list1.length - 1
1 <= list2.length <= 104

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
    ListNode* mergeInBetween(ListNode* l1, int a, int b, ListNode* l2) {
        ListNode* prev = l1;
        ListNode* after = l1;      

        for (int i = 0; i < a - 1; i++) 
            prev = prev->next;

        for (int i = 0; i < b + 1; i++) 
            after = after->next;
            
        prev->next = l2;
        ListNode* stop = l2;

        while (stop->next) {
            stop = stop->next;
        }
        stop->next = after;
    return l1;    
    }
};