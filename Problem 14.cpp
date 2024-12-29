//Problem 14
//URL: https://leetcode.com/problems/powx-n/
//Level: Easy
//Last updated: 2024/11/19
//Description: According to this problem, we have to calculate the result of x power n.
//Example:    

//Example 1:
// Input: x = 2.00000, n = 10
// Output: 1024.00000

// Example 2:
// Input: x = 2.50000, n = 2
// Output: 6.25000

// Example 2:
// Input: x = 10.00000, n = 3
// Output: 1000.00000

//Solution in C++ language
class Solution {
public:
    double myPow(double x, int n) {
        double temp = 1;
        if (n == 0)
            return 1;
        int power = abs(n);
        while (power) {
            if (power % 2 != 0) {
                temp = temp * x;
            }
            x = x * x;
            power = power / 2;
        }    
        return n > 0 ? temp : 1 / temp;
    }
};