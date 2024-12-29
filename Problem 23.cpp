//Problem 23
//URL: https://leetcode.com/problems/climbing-stairs/description/?envType=problem-list-v2&envId=dynamic-programming
//Level: Easy
//Last updated: 2024/12/3
/*Description: According to this problem, we determine ways to climb up stairs with 1 step or 2 steps each move.
/*Example:    

Example 1:
Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps

Example 2:
Input: n = 1
Output: 1
Explanation: There are 1 ways to climb to the top.
1. 1 steps

Example 3:
Input: n = 4
Output: 5
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step + 1 step + 1 step + 1 step
2. 1 step + 1 step + 2 steps
3. 1 step + 2 steps + 1 step
4. 2 steps + 1 step + 1 step
5. 2 steps + 2 steps
*/
//Solution in C++ language
class Solution {
public:
    int climbStairs(int n) {
        int methods[n + 1];
        methods[0] = 1;
        methods[1] = 1;
        int i = 2;
        while (i <= n) {
            methods[i] = methods[i - 1] + methods[i - 2];
            i++;
        }
    return methods[n];
    }
};