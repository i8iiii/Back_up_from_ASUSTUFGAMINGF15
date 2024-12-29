//Problem 30
//URL: https://leetcode.com/problems/fibonacci-number/
//Level: Easy
//Last updated: 2024/12/15
/*Description: According to this problem, we have to find the value of the nth fibonacci number.
Example:    

Example 1:
Input: n = 2
Output: 1
Explanation: F(2) = F(1) + F(0) = 1 + 0 = 1.

Example 2:
Input: n = 3
Output: 2
Explanation: F(2) = F(1) + F(0) = 1 + 0 = 1.
Explanation: F(3) = F(2) + F(1) = 1 + 1 = 2.

Example 3:
Input: n = 7
Output: 13
Explanation: F(2) = F(1) + F(0) = 1 + 0 = 1.
Explanation: F(3) = F(2) + F(1) = 1 + 1 = 2.
Explanation: F(4) = F(3) + F(2) = 2 + 1 = 3.
Explanation: F(5) = F(4) + F(3) = 3 + 2 = 5.
Explanation: F(6) = F(5) + F(4) = 5 + 3 = 8.
Explanation: F(7) = F(6) + F(5) = 8 + 5 = 13.
Solution in C++ language
 */
class Solution {
public:
    int fib(int n) {
        int f0 = 0;
        int f1 = 1;
        if (n == 0)
            return f0;
        if (n == 1)
            return f1;
        return fib(n - 1) + fib(n - 2);
    }
};